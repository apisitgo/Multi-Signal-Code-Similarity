import json, os, shutil, subprocess, zipfile, csv, time, sys, glob, collections
R='.'; P=json.load(open(f'{R}/data/pairs.json'))
groups=collections.defaultdict(list)
for p in P: groups[(p['ds'],p['pid'])].append(p)
def gdir(ds,pid):
    if ds=='irplag': return f'{R}/data/irplag/{pid}'
    d=f'{R}/runs/groups/{ds}/{pid}'
    if not os.path.exists(d):
        for p in groups[(ds,pid)]:
            for side in ('a','b'):
                s=f"{p['a']}_{p['b']}__{p[side]}"; os.makedirs(f'{d}/{s}',exist_ok=True)
                shutil.copy(p[side+'_path'],f'{d}/{s}/{p[side]}.java')
    return d
def names(p):
    if p['ds']=='irplag': return p['a'],p['b']
    k=f"{p['a']}_{p['b']}"; return f'{k}__{p["a"]}',f'{k}__{p["b"]}'
res={'jplag':{},'dolos':{}}; times=collections.defaultdict(float)
for (ds,pid),ps in sorted(groups.items()):
    d=gdir(ds,pid); tag=f'{ds}_{pid}'
    # JPlag
    t=time.time()
    out=f'{R}/runs/jplag/{tag}'
    subprocess.run(['java','-jar',f'{R}/tools/jplag-6.2.0.jar','-l','java','-n','-1','-M','RUN','-r',out,d],capture_output=True)
    times[('jplag',ds)]+=time.time()-t
    z=zipfile.ZipFile(out+'.jplag'); top=json.loads(z.read('topComparisons.json'))
    ri=json.loads(z.read('runInformation.json'))
    sim={}
    for c in top: sim[frozenset((c['firstSubmission'],c['secondSubmission']))]=c['similarities']['AVG']
    for p in ps:
        a,b=names(p); res['jplag'][p['id']]=sim.get(frozenset((a,b)))
    # Dolos
    t=time.time(); outd=f'{R}/runs/dolos/{tag}'; shutil.rmtree(outd,ignore_errors=True)
    files=sorted(glob.glob(f'{d}/*/*.java'))
    subprocess.run(['npx','--prefix',f'{R}/tools/dolos','dolos','run','-l','java','-f','csv','-o',outd]+files,capture_output=True,cwd=f'{R}/tools/dolos')
    times[('dolos',ds)]+=time.time()-t
    dsim={}
    for row in csv.DictReader(open(f'{outd}/pairs.csv')):
        la=row['leftFilePath'].split('/')[-2]; lb=row['rightFilePath'].split('/')[-2]
        dsim[frozenset((la,lb))]=float(row['similarity'])
    for p in ps:
        a,b=names(p); res['dolos'][p['id']]=dsim.get(frozenset((a,b)))
    print(tag,len(ps),'jplag failed',len(ri.get('failedSubmissions',[])),flush=True)
json.dump({'res':res,'times':{f'{k[0]}|{k[1]}':v for k,v in times.items()}},open(f'{R}/data/baselines.json','w'))
for t in res: print(t, sum(v is None for v in res[t].values()),'missing of',len(res[t]))
