import json,glob,random,os,shutil,subprocess,time,itertools
from v2 import Doc,signals,hand
R='.'; random.seed(7)
files=sorted(glob.glob(f'{R}/conplag/versions/version_1/*/*.java'))
res={}
for n in [50,100,200]:
    pick=random.sample(files,n); d=f'{R}/runs/rt/{n}'; shutil.rmtree(d,ignore_errors=True)
    for i,f in enumerate(pick): os.makedirs(f'{d}/s{i:03d}'); shutil.copy(f,f'{d}/s{i:03d}/Main.java')
    paths=sorted(glob.glob(f'{d}/*/Main.java'))
    json.dump([{'id':i,'a':a,'b':b} for i,(a,b) in enumerate(itertools.combinations(paths,2))],open(f'{d}.json','w'))
    t=time.time(); subprocess.run(['node','v1.js',f'{d}.json',f'{d}.v1out'],cwd=f'{R}/spii',capture_output=True); t_v1=time.time()-t
    t=time.time(); docs=[Doc(open(p).read()) for p in paths]; [hand(signals(a,b)) for a,b in itertools.combinations(docs,2)]; t_v2=time.time()-t
    t=time.time(); subprocess.run(['java','-jar',f'{R}/tools/jplag-6.2.0.jar','-l','java','-n','-1','-M','RUN','-r',f'{d}_jp',d],capture_output=True); t_jp=time.time()-t
    t=time.time(); subprocess.run(['npx','dolos','run','-l','java','-f','csv','-o',f'{d}_do']+paths,cwd=f'{R}/tools/dolos',capture_output=True); t_do=time.time()-t
    res[n]=dict(pairs=n*(n-1)//2,v1=t_v1,v2=t_v2,jplag=t_jp,dolos=t_do); print(n,res[n],flush=True)
json.dump(res,open(f'{R}/data/runtime.json','w'))
