"""SPII-Bench evaluation: builds pairs, runs SPII-v1/v2, JPlag, Dolos (with and without
starter-code handling), computes metrics. Output: data/bench_results.json"""
import json, os, glob, itertools, subprocess, shutil, zipfile, csv, collections, time
import numpy as np
from sklearn.metrics import roc_auc_score
from v2 import Doc, signals, hand
from analysis_lib import metrics, cluster_boot, delong

R = '.'; BN = f'{R}/bench'
U = json.load(open(f'{BN}/units.json'))
rng = np.random.default_rng(20260928)
POS_SRC = [(f'RA{r}', f'L{k}') for r in (1, 2) for k in range(1, 7)] + [(f'LLM{m}', f'P{k}') for m in 'AB' for k in (1, 2, 3)]
NEG_SRC = ['IND1', 'IND2', 'IND3', 'IND4', 'GEN1', 'GEN2']

# ---------------- files and pairs ----------------
files = {}  # (uid, name) -> path
for u in U:
    uid, ext = u['uid'], u['ext']
    files[(uid, 'orig')] = f'{BN}/orig/{uid}.{ext}'
    for src, var in POS_SRC: files[(uid, f'{src}_{var}')] = f'{BN}/out/{src}/{uid}_{var}.{ext}'
    for src in NEG_SRC: files[(uid, src)] = f'{BN}/out/{src}/{uid}.{ext}'
assert all(os.path.exists(p) for p in files.values())
pairs = []
for u in U:
    uid = u['uid']
    for src, var in POS_SRC:
        cat = f'L{var[1]}' if src.startswith('RA') else f'LLM-{var}'
        pairs.append(dict(uid=uid, lang=u['lang'], a='orig', b=f'{src}_{var}', label=1, cat=cat, src=src))
    for s in NEG_SRC:
        pairs.append(dict(uid=uid, lang=u['lang'], a='orig', b=s, label=0, cat='GEN' if s.startswith('GEN') else 'IND', src=s))
    for x, y in itertools.combinations(NEG_SRC, 2):
        pairs.append(dict(uid=uid, lang=u['lang'], a=x, b=y, label=0, cat='indep-indep', src=f'{x}-{y}'))
for i, p in enumerate(pairs): p['id'] = i
print('pairs', len(pairs), collections.Counter(p['label'] for p in pairs))

S = {}  # method -> {pair id: score}

# ---------------- SPII-v1 (production code via node harness) ----------------
inp = [{'id': p['id'], 'a': files[(p['uid'], p['a'])], 'b': files[(p['uid'], p['b'])]} for p in pairs]
json.dump(inp, open(f'{R}/data/bench_v1_in.json', 'w'))
subprocess.run(['node', 'v1.js', f'{R}/data/bench_v1_in.json', f'{R}/data/bench_v1_out.json'], cwd=f'{R}/spii', check=True)
V1 = {r['id']: r for r in json.load(open(f'{R}/data/bench_v1_out.json'))['results']}
S['SPII-v1'] = {k: v['overall'] / 100 for k, v in V1.items()}

# ---------------- SPII-v2 ----------------
lang_of = {u['uid']: u['lang'] for u in U}; ext_of = {u['uid']: u['ext'] for u in U}
starter_doc = {u['uid']: Doc(open(f"{BN}/tasks/{u['uid']}/starter.{u['ext']}").read(), u['lang']) for u in U}
cache = {}
def doc(uid, name, base):
    key = (uid, name, base)
    if key not in cache:
        code = open(files[(uid, name)], encoding='utf-8', errors='replace').read()
        cache[key] = Doc(code, lang_of[uid], base=starter_doc[uid] if base else None)
    return cache[key]
V2 = {}; V2b = {}
for p in pairs:
    s = signals(doc(p['uid'], p['a'], False), doc(p['uid'], p['b'], False)); s['overall'] = hand(s); V2[p['id']] = s
    s = signals(doc(p['uid'], p['a'], True), doc(p['uid'], p['b'], True)); s['overall'] = hand(s); V2b[p['id']] = s
S['SPII-v2'] = {k: v['overall'] for k, v in V2.items()}
S['SPII-v2 + starter subtraction'] = {k: v['overall'] for k, v in V2b.items()}
for sig in ['token', 'fingerprint', 'lineset', 'text']:
    S[f'v2:{sig}'] = {k: v[sig] for k, v in V2.items()}
    S[f'v1:{sig}'] = {k: v[sig] for k, v in V1.items()}

# robust within-problem standardisation on simulated classes (orig + 6 independent + 3 random copies)
def robust_z(base, reps=100):
    out = collections.defaultdict(list)
    for _ in range(reps):
        st = {}
        for u in U:
            uid = u['uid']; pos = [f'{s}_{v}' for s, v in POS_SRC]
            pop = ['orig'] + NEG_SRC + list(rng.choice(pos, 3, replace=False))
            vals = [hand(signals(doc(uid, a, base), doc(uid, b, base))) for a, b in itertools.combinations(pop, 2)]
            med = float(np.median(vals)); mad = max(float(np.median(np.abs(np.array(vals) - med))) * 1.4826, 1e-3)
            st[uid] = (med, mad)
        src = V2b if base else V2
        for p in pairs:
            out[p['id']].append((src[p['id']]['overall'] - st[p['uid']][0]) / st[p['uid']][1])
    return out
Z = robust_z(False); Zb = robust_z(True)
Z_reps = {k: v for k, v in Z.items()}; Zb_reps = {k: v for k, v in Zb.items()}

# ---------------- JPlag & Dolos ----------------
def run_tools(u):
    uid, ext = u['uid'], u['ext']; d = f'{R}/runs/bench/{uid}'; shutil.rmtree(d, ignore_errors=True)
    names = [n for (x, n) in files if x == uid]
    for n in names:
        os.makedirs(f'{d}/subs/{n}'); shutil.copy(files[(uid, n)], f'{d}/subs/{n}/main.{ext}')
    os.makedirs(f'{d}/base'); shutil.copy(f'{BN}/tasks/{uid}/starter.{ext}', f'{d}/base/main.{ext}')
    jl = 'python3' if ext == 'py' else 'c'; dl = 'python' if ext == 'py' else 'c'
    out = {}
    for tag, extra in [('JPlag', []), ('JPlag + base code', ['-bc', f'{d}/base']), ('JPlag + match merging', ['--match-merging'])]:
        r = f'{d}/jp_{len(extra)}_{tag[-4:]}'
        subprocess.run(['java', '-jar', f'{R}/tools/jplag-6.2.0.jar', '-l', jl, '-n', '-1', '-M', 'RUN', '--cluster-skip', '-r', r, *extra, f'{d}/subs'], capture_output=True)
        if not os.path.exists(r + '.jplag'):  # JPlag rejected the run (e.g. base code below minimum match length)
            out[tag] = (out['JPlag'][0], ['__RUN_REJECTED__']); continue
        z = zipfile.ZipFile(r + '.jplag'); top = json.loads(z.read('topComparisons.json'))
        fails = json.loads(z.read('runInformation.json')).get('failedSubmissions', [])
        out[tag] = ({frozenset((c['firstSubmission'], c['secondSubmission'])): c['similarities']['AVG'] for c in top}, [f['submissionId'] for f in fails])
    paths = sorted(glob.glob(f'{d}/subs/*/main.{ext}'))
    for tag, extra in [('Dolos', []), ('Dolos + ignore starter', ['-i', f'{d}/base/main.{ext}'])]:
        o = f'{d}/do_{len(extra)}'; shutil.rmtree(o, ignore_errors=True)
        subprocess.run(['npx', 'dolos', 'run', '-l', dl, '-f', 'csv', '-o', o, *extra, *paths], cwd=f'{R}/tools/dolos', capture_output=True)
        sim = {}
        for row in csv.DictReader(open(f'{o}/pairs.csv')):
            sim[frozenset((row['leftFilePath'].split('/')[-2], row['rightFilePath'].split('/')[-2]))] = float(row['similarity'])
        out[tag] = (sim, [])
    return out
TOOLFAIL = collections.defaultdict(list)
t0 = time.time()
for u in U:
    res = run_tools(u)
    for tag, (sim, fails) in res.items():
        S.setdefault(tag, {}); TOOLFAIL[tag] += [f"{u['uid']}:{f}" for f in fails]
        for p in pairs:
            if p['uid'] == u['uid']:
                S[tag][p['id']] = sim.get(frozenset((p['a'], p['b'])), 0.0)
print('tools done', time.time() - t0)

# ---------------- metrics ----------------
METHODS = ['SPII-v1', 'SPII-v2', 'SPII-v2 + starter subtraction', 'JPlag', 'JPlag + base code', 'JPlag + match merging', 'Dolos', 'Dolos + ignore starter']
OUT = {'n_pairs': len(pairs), 'n_pos': sum(p['label'] for p in pairs), 'tool_failures': dict(TOOLFAIL)}
def subset(lang=None, cats=None, negcats=None):
    return [p for p in pairs if (lang is None or p['lang'] == lang) and ((p['label'] == 1 and (cats is None or p['cat'] in cats)) or (p['label'] == 0 and (negcats is None or p['cat'] in negcats)))]
main = {}
for lang in ['python', 'c', None]:
    ps = subset(lang); y = [p['label'] for p in ps]; g = [p['uid'] for p in ps]; row = {}
    for m in METHODS:
        s = [S[m][p['id']] for p in ps]; r = metrics(y, s); r['ci'] = cluster_boot(y, s, g, n=2000); row[m] = r
    for m in METHODS:
        for ref in ['SPII-v1', 'JPlag', 'Dolos']:
            if m != ref: row[m][f'dl_{ref}'] = delong(y, [S[m][p['id']] for p in ps], [S[ref][p['id']] for p in ps])
    # robust z (mean over simulated classes)
    for name, ZZ in [('SPII-v2 + robust z', Z_reps), ('SPII-v2 + starter subtraction + robust z', Zb_reps)]:
        ms = [metrics(y, [ZZ[p['id']][k] for p in ps]) for k in range(len(next(iter(ZZ.values()))))]
        row[name] = {kk: float(np.mean([x[kk] for x in ms])) for kk in ms[0]}; row[name]['sd_auroc'] = float(np.std([x['auroc'] for x in ms]))
    row['_n'] = dict(pos=sum(y), neg=len(y) - sum(y), units=len(set(g)))
    main[lang or 'all'] = row
OUT['main'] = main
# per category AUROC (positives of a category vs all negatives), per language
cats = ['L1', 'L2', 'L3', 'L4', 'L5', 'L6', 'LLM-P1', 'LLM-P2', 'LLM-P3']
percat = {}
for lang in ['python', 'c']:
    percat[lang] = {}
    for c in cats:
        ps = subset(lang, {c}); y = [p['label'] for p in ps]
        percat[lang][c] = {m: roc_auc_score(y, [S[m][p['id']] for p in ps]) for m in METHODS + [f'v2:{x}' for x in ['token', 'fingerprint', 'lineset', 'text']]}
OUT['percat'] = percat
# LLM model split
OUT['llm_models'] = {}
for lang in ['python', 'c']:
    for src in ['LLMA', 'LLMB']:
        ps = [p for p in pairs if p['lang'] == lang and (p['label'] == 0 or p['src'] == src)]
        y = [p['label'] for p in ps]
        OUT['llm_models'][f'{lang}|{src}'] = {m: roc_auc_score(y, [S[m][p['id']] for p in ps]) for m in METHODS}
# hard negatives: share of (GEN pair, positive pair) within a unit where GEN pair scores >= positive pair
hn = {}
for m in ['SPII-v2', 'SPII-v2 + starter subtraction', 'JPlag', 'Dolos']:
    hn[m] = {}
    for group, cs in [('L1-L3', {'L1', 'L2', 'L3'}), ('L4-L6', {'L4', 'L5', 'L6'}), ('LLM', {'LLM-P1', 'LLM-P2', 'LLM-P3'})]:
        tot = win = 0
        for u in U:
            gens = [S[m][p['id']] for p in pairs if p['uid'] == u['uid'] and p['cat'] == 'GEN']
            poss = [S[m][p['id']] for p in pairs if p['uid'] == u['uid'] and p['cat'] in cs]
            for g_ in gens:
                for q in poss: tot += 1; win += g_ >= q
        hn[m][group] = win / tot
OUT['hard_neg'] = hn
# medians by category (SPII-v2 raw vs starter-subtracted)
OUT['medians'] = {m: {c: float(np.median([S[m][p['id']] for p in pairs if p['cat'] == c])) for c in cats + ['IND', 'GEN', 'indep-indep']} for m in ['SPII-v2', 'SPII-v2 + starter subtraction', 'JPlag', 'Dolos']}
# v1 defect exposure
pyfiles = [p for (uid, n), p in files.items() if uid.startswith('PY')]
cfiles = [p for (uid, n), p in files.items() if uid.startswith('C')]
import re
OUT['defects'] = dict(py_files=len(pyfiles), py_floor=sum(1 for f in pyfiles if re.search(r'\s//\s', open(f).read())),
                      c_files=len(cfiles), c_include=sum(1 for f in cfiles if '#include' in open(f).read()))
# file sizes
loc = {k: sum(1 for l in open(v) if l.strip()) for k, v in files.items()}
OUT['loc'] = {lang: {'orig_min': min(loc[(u['uid'], 'orig')] for u in U if u['lang'] == lang), 'orig_max': max(loc[(u['uid'], 'orig')] for u in U if u['lang'] == lang),
                     'all_median': float(np.median([v for (uid, n), v in loc.items() if lang_of[uid] == lang]))} for lang in ['python', 'c']}
OUT['n_files'] = len(files)
json.dump(OUT, open(f'{R}/data/bench_results.json', 'w'), indent=1)
json.dump({m: {str(k): v for k, v in S[m].items()} for m in S}, open(f'{R}/data/bench_scores.json', 'w'))
json.dump(pairs, open(f'{R}/data/bench_pairs.json', 'w'))
print('done')
