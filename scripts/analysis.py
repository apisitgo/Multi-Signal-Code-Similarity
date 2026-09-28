import json, itertools, random, collections, time, glob
import numpy as np
from scipy import stats
from sklearn.metrics import roc_auc_score, average_precision_score, roc_curve
from sklearn.linear_model import LogisticRegression
from v2 import Doc, signals, hand

R = '.'
P = json.load(open(f'{R}/data/pairs.json'))
V1 = {r['id']: r for r in json.load(open(f'{R}/data/v1_out.json'))['results']}
V2 = {int(k): v for k, v in json.load(open(f'{R}/data/v2_out.json')).items()}
B = json.load(open(f'{R}/data/baselines.json'))['res']
SIG = ['token', 'fingerprint', 'lineset', 'text']
rng = np.random.default_rng(20260927)


def score(method, pid):
    """Raw score of a pair (id) under a named method."""
    if method == 'JPlag': v = B['jplag'][str(pid)]; return 0.0 if v is None else v
    if method == 'Dolos': return B['dolos'][str(pid)]
    if method == 'SPII-v1': return V1[pid]['overall'] / 100
    if method.startswith('v1:'): return V1[pid][method[3:]]
    if method == 'SPII-v2 (hand)': return V2[pid]['overall']
    if method == 'SPII-v2 (mean)': return np.mean([V2[pid][s] for s in SIG])
    if method == 'SPII-v2 (max)': return max(V2[pid][s] for s in SIG)
    if method.startswith('v2:'): return V2[pid][method[3:]]
    raise KeyError(method)


def tpr_at(y, s, fpr_t):
    fpr, tpr, _ = roc_curve(y, s)
    return float(np.interp(fpr_t, fpr, tpr))


def metrics(y, s):
    y = np.asarray(y); s = np.asarray(s)
    return dict(auroc=roc_auc_score(y, s), auprc=average_precision_score(y, s),
                tpr1=tpr_at(y, s, 0.01), tpr5=tpr_at(y, s, 0.05))


def cluster_boot(y, s, g, fn=roc_auc_score, n=2000):
    """Cluster (problem-level) bootstrap 95% CI."""
    y, s, g = map(np.asarray, (y, s, g)); groups = np.unique(g)
    idx = {k: np.where(g == k)[0] for k in groups}; vals = []
    for _ in range(n):
        pick = rng.choice(groups, len(groups), replace=True)
        ii = np.concatenate([idx[k] for k in pick])
        if len(np.unique(y[ii])) < 2: continue
        vals.append(fn(y[ii], s[ii]))
    return float(np.percentile(vals, 2.5)), float(np.percentile(vals, 97.5))


# ---- DeLong paired test (Sun & Xu 2014 fast implementation) ----
def _midrank(x):
    J = np.argsort(x); Z = x[J]; N = len(x); T = np.zeros(N); i = 0
    while i < N:
        j = i
        while j < N and Z[j] == Z[i]: j += 1
        T[i:j] = 0.5 * (i + j - 1) + 1; i = j
    T2 = np.empty(N); T2[J] = T; return T2


def delong(y, s1, s2):
    y = np.asarray(y); order = np.argsort(-y); y = y[order]
    preds = np.vstack([np.asarray(s1)[order], np.asarray(s2)[order]])
    m = int(y.sum()); n = len(y) - m
    tx = np.array([_midrank(p[:m]) for p in preds]); ty = np.array([_midrank(p[m:]) for p in preds])
    tz = np.array([_midrank(p) for p in preds])
    aucs = tz[:, :m].sum(axis=1) / m / n - (m + 1.0) / 2.0 / n
    v01 = (tz[:, :m] - tx) / n; v10 = 1.0 - (tz[:, m:] - ty) / m
    cov = np.cov(v01) / m + np.cov(v10) / n
    l = np.array([1, -1]); z = (aucs[0] - aucs[1]) / np.sqrt(l @ cov @ l)
    return float(aucs[0] - aucs[1]), float(2 * stats.norm.sf(abs(z)))


def subset(ds, sets=None):
    return [p for p in P if p['ds'] == ds and (sets is None or p['set'] in sets)]


OUT = {}
METHODS = ['JPlag', 'Dolos', 'SPII-v1', 'SPII-v2 (hand)', 'SPII-v2 (mean)', 'SPII-v2 (max)']
EVALS = {
    'IR-Plag (anchored)': subset('irplag', {'anchor'}),
    'IR-Plag (all)': subset('irplag'),
    'ConPlag raw (test)': subset('conplag_raw', {'test'}),
    'ConPlag template-free (test)': subset('conplag_tf', {'test'}),
}

# ---------- Learned fusion (logistic regression on the four v2 signals) ----------
def feats(ps): return np.array([[V2[p['id']][s] for s in SIG] for p in ps])
def lab(ps): return np.array([p['label'] for p in ps])
LR = {}
# IR-Plag: leave-one-case-out
for name in ['IR-Plag (anchored)', 'IR-Plag (all)']:
    ps = EVALS[name]; pred = {}
    for case in sorted({p['pid'] for p in ps}):
        tr = [p for p in ps if p['pid'] != case]; te = [p for p in ps if p['pid'] == case]
        m = LogisticRegression(max_iter=1000).fit(feats(tr), lab(tr))
        for p, v in zip(te, m.predict_proba(feats(te))[:, 1]): pred[p['id']] = v
    LR[name] = pred
for ds, name in [('conplag_raw', 'ConPlag raw (test)'), ('conplag_tf', 'ConPlag template-free (test)')]:
    tr = subset(ds, {'train'}); te = EVALS[name]
    m = LogisticRegression(max_iter=1000).fit(feats(tr), lab(tr))
    LR[name] = dict(zip([p['id'] for p in te], m.predict_proba(feats(te))[:, 1]))
    OUT[f'lr_coef_{ds}'] = dict(zip(SIG, m.coef_[0].tolist()))
# Cross-dataset: train on all IR-Plag, test ConPlag; train on ConPlag raw train, test IR-Plag
m_ir = LogisticRegression(max_iter=1000).fit(feats(subset('irplag')), lab(subset('irplag')))
OUT['lr_coef_irplag'] = dict(zip(SIG, m_ir.coef_[0].tolist()))
m_cp = LogisticRegression(max_iter=1000).fit(feats(subset('conplag_raw', {'train'})), lab(subset('conplag_raw', {'train'})))
XD = {}
for name in ['ConPlag raw (test)', 'ConPlag template-free (test)']:
    te = EVALS[name]; XD[name] = dict(zip([p['id'] for p in te], m_ir.predict_proba(feats(te))[:, 1]))
for name in ['IR-Plag (anchored)', 'IR-Plag (all)']:
    te = EVALS[name]; XD[name] = dict(zip([p['id'] for p in te], m_cp.predict_proba(feats(te))[:, 1]))


def s_of(method, p, evalname):
    if method == 'SPII-v2 (LR, in-dataset)': return LR[evalname][p['id']]
    if method == 'SPII-v2 (LR, cross-dataset)': return XD[evalname][p['id']]
    return score(method, p['id'])

ALLM = METHODS + ['SPII-v2 (LR, in-dataset)', 'SPII-v2 (LR, cross-dataset)']
main = {}
for en, ps in EVALS.items():
    y = lab(ps); g = [p['pid'] for p in ps]; row = {}
    for mth in ALLM:
        s = [s_of(mth, p, en) for p in ps]
        r = metrics(y, s); r['auroc_ci'] = cluster_boot(y, s, g); row[mth] = r
    # paired DeLong vs Dolos and vs SPII-v1
    ref = {k: [s_of(k, p, en) for p in ps] for k in ['Dolos', 'SPII-v1', 'JPlag']}
    for mth in ALLM:
        s = [s_of(mth, p, en) for p in ps]
        for k in ref:
            if k != mth: row[mth][f'delong_vs_{k}'] = delong(y, s, ref[k])
    row['_n'] = dict(pos=int(y.sum()), neg=int(len(y) - y.sum()), problems=len(set(g)))
    main[en] = row
OUT['main'] = main

# Holm correction over the DeLong p-values vs Dolos (per evaluation set)
for en, row in main.items():
    keys = [m for m in ALLM if m != 'Dolos']; ps_ = [row[m]['delong_vs_Dolos'][1] for m in keys]
    order = np.argsort(ps_); adj = [0] * len(ps_); run = 0
    for rank, i in enumerate(order):
        run = max(run, min(1, (len(ps_) - rank) * ps_[i])); adj[i] = run
    for m, a in zip(keys, adj): row[m]['holm_vs_Dolos'] = a

# ---------- RQ1: single signals, per obfuscation level (IR-Plag, anchored negatives) ----------
neg = [p for p in EVALS['IR-Plag (anchored)'] if p['label'] == 0]
lvl = {}
SINGLE = [f'v1:{s}' for s in SIG] + [f'v2:{s}' for s in SIG] + ['SPII-v1', 'SPII-v2 (hand)', 'JPlag', 'Dolos']
for L in ['L1', 'L2', 'L3', 'L4', 'L5', 'L6']:
    pos = [p for p in EVALS['IR-Plag (anchored)'] if p['level'] == L]
    ps = pos + neg; y = lab(ps); lvl[L] = {'n_pos': len(pos)}
    for mth in SINGLE:
        lvl[L][mth] = roc_auc_score(y, [score(mth, p['id']) for p in ps])
OUT['levels'] = lvl
# single signals pooled on each eval set
single = {}
for en, ps in EVALS.items():
    y = lab(ps); single[en] = {m: metrics(y, [score(m, p['id']) for p in ps]) for m in [f'v1:{s}' for s in SIG] + [f'v2:{s}' for s in SIG]}
OUT['single'] = single

# ---------- RQ3: problem-aware calibration (robust within-problem standardisation) ----------
DOCS = {}
def doc(path):
    if path not in DOCS: DOCS[path] = Doc(open(path, encoding='utf-8', errors='replace').read(), 'java')
    return DOCS[path]

def robust_stats(paths):
    vals = [hand(signals(doc(a), doc(b))) for a, b in itertools.combinations(paths, 2)]
    med = float(np.median(vals)); mad = float(np.median(np.abs(np.array(vals) - med))) * 1.4826
    return med, max(mad, 1e-3)

# IR-Plag: simulate classes with realistic prevalence (original + 15 independent + m plagiarised copies)
ir_files = collections.defaultdict(dict)
for p in subset('irplag'):
    ir_files[p['pid']][p['a']] = p['a_path']; ir_files[p['pid']][p['b']] = p['b_path']
calib = {'irplag_sim': [], 'irplag_sim_raw': []}
ps_all = EVALS['IR-Plag (all)']; y_all = lab(ps_all)
for rep in range(100):
    st = {}
    for case, fm in ir_files.items():
        plag = sorted(k for k in fm if k.startswith('p')); pick = list(rng.choice(plag, 3, replace=False))
        pop = [fm['orig']] + [fm[k] for k in fm if k.startswith('n_')] + [fm[k] for k in pick]
        st[case] = robust_stats(pop)
    raw = [V2[p['id']]['overall'] for p in ps_all]
    cal = [(V2[p['id']]['overall'] - st[p['pid']][0]) / st[p['pid']][1] for p in ps_all]
    calib['irplag_sim'].append(metrics(y_all, cal)); calib['irplag_sim_raw'].append(metrics(y_all, raw))
OUT['calib_irplag'] = {k: {m: [float(np.mean([r[m] for r in v])), float(np.std([r[m] for r in v]))] for m in v[0]} for k, v in calib.items()}

# ConPlag: population = every distinct submission of the problem present in the dataset
for ds, en in [('conplag_raw', 'ConPlag raw (test)'), ('conplag_tf', 'ConPlag template-free (test)')]:
    files = collections.defaultdict(dict)
    for p in subset(ds):
        files[p['pid']].setdefault(p['a'], p['a_path']); files[p['pid']].setdefault(p['b'], p['b_path'])
    st = {pid: robust_stats(list(fm.values())) for pid, fm in files.items()}
    ps = EVALS[en]; y = lab(ps); g = [p['pid'] for p in ps]
    raw = [V2[p['id']]['overall'] for p in ps]
    cal = [(V2[p['id']]['overall'] - st[p['pid']][0]) / st[p['pid']][1] for p in ps]
    OUT[f'calib_{ds}'] = {'raw': metrics(y, raw), 'cal': metrics(y, cal), 'delong': delong(y, cal, raw),
                          'raw_ci': cluster_boot(y, raw, g), 'cal_ci': cluster_boot(y, cal, g),
                          'pop_sizes': {pid: len(fm) for pid, fm in files.items()}}

# ---------- Program length and independent-pair similarity (motivation for RQ3) ----------
length = {}
for case, fm in ir_files.items():
    loc = sum(1 for l in open(fm['orig'], encoding='utf-8', errors='replace') if l.strip())
    ind = [p for p in subset('irplag', {'indep'}) if p['pid'] == case]
    pos = [p for p in subset('irplag', {'anchor'}) if p['pid'] == case and p['label'] == 1]
    length[case] = dict(loc=loc, indep_median=float(np.median([V2[p['id']]['overall'] for p in ind])),
                        indep_p90=float(np.percentile([V2[p['id']]['overall'] for p in ind], 90)),
                        plag_median=float(np.median([V2[p['id']]['overall'] for p in pos])),
                        v1_indep_median=float(np.median([V1[p['id']]['overall'] / 100 for p in ind])))
OUT['length'] = length
json.dump(OUT, open(f'{R}/data/results.json', 'w'), indent=1)
print('done')
