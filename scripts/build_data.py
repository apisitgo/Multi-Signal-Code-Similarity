import os, glob, json, csv, shutil, itertools
root='.'
out=f'{root}/data'
# ---------- IR-Plag ----------
ir=f'{root}/irplag/IR-Plag-Dataset'
pairs=[]
for case in sorted(os.listdir(ir)):
    pdir=f'{out}/irplag/{case}'; os.makedirs(pdir,exist_ok=True)
    subs={}
    o=glob.glob(f'{ir}/{case}/original/*.java')[0]
    subs['orig']=o
    for f in glob.glob(f'{ir}/{case}/plagiarized/L*/*/*.java'):
        lv=f.split('/')[-3]; n=f.split('/')[-2]; subs[f'p{lv}_{n}']=f
    for f in glob.glob(f'{ir}/{case}/non-plagiarized/*/*.java'):
        n=f.split('/')[-2]; subs[f'n_{n}']=f
    for k,f in subs.items():
        d=f'{pdir}/{k}'; os.makedirs(d,exist_ok=True); shutil.copy(f,f'{d}/{os.path.basename(f)}')
    for k in subs:
        if k=='orig': continue
        if k.startswith('p'):
            pairs.append(dict(ds='irplag',pid=case,a='orig',b=k,label=1,level=k[1:3],set='anchor'))
        else:
            pairs.append(dict(ds='irplag',pid=case,a='orig',b=k,label=0,level='NP',set='anchor'))
    non=sorted(k for k in subs if k.startswith('n_'))
    for x,y in itertools.combinations(non,2):
        pairs.append(dict(ds='irplag',pid=case,a=x,b=y,label=0,level='NP',set='indep'))
# ---------- ConPlag ----------
cp=f'{root}/conplag/versions'
labels=list(csv.DictReader(open(f'{cp}/labels.csv')))
test=set(l.strip() for l in open(f'{cp}/test_pairs.csv') if l.strip())
for ver,name in [('version_1','conplag_raw'),('version_2','conplag_tf')]:
    for l in labels:
        pdir=f'{out}/{name}/{l["problem"]}'
        for s in (l['sub1'],l['sub2']):
            d=f'{pdir}/{s}'; os.makedirs(d,exist_ok=True)
            src=f'{cp}/{ver}/{l["sub1"]}_{l["sub2"]}/{s}.java'
            if not os.path.exists(f'{d}/{s}.java'): shutil.copy(src,f'{d}/{s}.java')
        key=f'{l["sub1"]}_{l["sub2"]}'
        pairs.append(dict(ds=name,pid=l['problem'],a=l['sub1'],b=l['sub2'],label=int(l['verdict']),level='-',set='test' if key in test else 'train'))
for i,p in enumerate(pairs): p['id']=i
json.dump(pairs,open(f'{out}/pairs.json','w'))
import collections
c=collections.Counter((p['ds'],p['set'],p['label']) for p in pairs); 
for k,v in sorted(c.items()): print(k,v)
