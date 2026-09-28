import json,subprocess,zipfile,os,numpy as np
from analysis_lib import metrics,cluster_boot,delong
from sklearn.metrics import roc_auc_score
R='.'; P=json.load(open(f'{R}/data/bench_pairs.json')); S=json.load(open(f'{R}/data/bench_scores.json')); O=json.load(open(f'{R}/data/bench_results.json'))
U=json.load(open(f'{R}/bench/units.json'))
sc={}; fails=0
for u in U:
    d=f"{R}/runs/bench/{u['uid']}"; r=f'{d}/jp_t6'
    subprocess.run(['java','-jar',f'{R}/tools/jplag-6.2.0.jar','-l','python3' if u['ext']=='py' else 'c','-t','6','-n','-1','-M','RUN','--cluster-skip','-r',r,f'{d}/subs'],capture_output=True)
    z=zipfile.ZipFile(r+'.jplag'); top=json.loads(z.read('topComparisons.json')); fails+=len(json.loads(z.read('runInformation.json')).get('failedSubmissions',[]))
    sim={frozenset((c['firstSubmission'],c['secondSubmission'])):c['similarities']['AVG'] for c in top}
    for p in P:
        if p['uid']==u['uid']: sc[str(p['id'])]=sim.get(frozenset((p['a'],p['b'])),0.0)
S['JPlag (min. match 6)']=sc
m='JPlag (min. match 6)'
for lang in ['python','c','all']:
    ps=[p for p in P if lang=='all' or p['lang']==lang]; y=[p['label'] for p in ps]; g=[p['uid'] for p in ps]; s=[sc[str(p['id'])] for p in ps]
    r=metrics(y,s); r['ci']=cluster_boot(y,s,g,n=2000)
    for ref in ['SPII-v1','JPlag','Dolos']: r[f'dl_{ref}']=delong(y,s,[S[ref][str(p['id'])] for p in ps])
    O['main'][lang][m]=r; print(lang,r)
for lang in ['python','c']:
    for c in O['percat'][lang]:
        ps=[p for p in P if p['lang']==lang and (p['label']==0 or p['cat']==c)]
        O['percat'][lang][c][m]=roc_auc_score([p['label'] for p in ps],[sc[str(p['id'])] for p in ps])
O['jplag_t6_failed']=fails; O['jplag_t6_zero']=float(np.mean([v==0 for v in sc.values()]))
json.dump(O,open(f'{R}/data/bench_results.json','w'),indent=1); json.dump(S,open(f'{R}/data/bench_scores.json','w'))
print(fails,O['jplag_t6_zero'])
