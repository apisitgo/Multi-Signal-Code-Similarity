import json,time
from v2 import Doc, signals, hand
P=json.load(open('data/pairs.json')); cache={}
def doc(p):
    if p not in cache: cache[p]=Doc(open(p,encoding='utf-8',errors='replace').read(),'java')
    return cache[p]
out={}; t=time.time()
for p in P:
    s=signals(doc(p['a_path']),doc(p['b_path'])); s['overall']=hand(s); out[p['id']]=s
print('v2 secs',time.time()-t)
json.dump(out,open('data/v2_out.json','w'))
