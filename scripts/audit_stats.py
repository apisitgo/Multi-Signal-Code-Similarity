"""Human-audit statistics for SPII-Bench (two raters, 60 pairs)."""
import json
from collections import Counter
from sklearn.metrics import cohen_kappa_score
import os; D=os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','data')+'/'
RATERS=[json.load(open(D+f'audit_r{i}.json')) for i in (1,2)]  # rater 2 = round-2 file 2-1
for R in RATERS: R.sort(key=lambda x:x['item'])
assert all([x['item'] for x in R]==list(range(1,61)) for R in RATERS)
def grp(c): return 'L13' if c in ('L1','L2','L3') else 'L46' if c in ('L4','L5','L6') else 'LLM' if c.startswith('LLM') else c
def per_rater(R):
    y=[x['label'] for x in R]; h=[int(x['q1']=='yes') for x in R]
    s=lambda f:sum(1 for x in R if f(x))
    return dict(L13=s(lambda x:grp(x['cat'])=='L13' and x['q1']=='yes'), L46=s(lambda x:grp(x['cat'])=='L46' and x['q1']=='yes'),
        LLM=s(lambda x:grp(x['cat'])=='LLM' and x['q1']=='yes'), negyes=s(lambda x:x['label']==0 and x['q1']=='yes'),
        ind=s(lambda x:x['cat']=='IND' and x['q1']=='yes'), gen=s(lambda x:x['cat']=='GEN' and x['q1']=='yes'),
        agree=sum(a==b for a,b in zip(y,h)), kappa=cohen_kappa_score(y,h),
        q2pos=s(lambda x:x['label']==1 and x['q2']=='yes'), q2neg=s(lambda x:x['label']==0 and x['q2']=='no'))
def fleiss(q):
    n=len(RATERS); P=[]; tot=Counter()
    for i in range(60):
        c=Counter(R[i][q] for R in RATERS); tot.update(c); P.append((sum(v*v for v in c.values())-n)/(n*(n-1)))
    pe=sum((v/(60*n))**2 for v in tot.values()); pb=sum(P)/60; return (pb-pe)/(1-pe)
PR=[per_rater(R) for R in RATERS]
PAIR={q:cohen_kappa_score([x[q] for x in RATERS[0]],[x[q] for x in RATERS[1]]) for q in ('q1','q2')}
AGREE={q:sum(a[q]==b[q] for a,b in zip(*RATERS)) for q in ('q1','q2')}
# unanimous Q1 agreement by group
UN={g:(sum(1 for i in range(60) if grp(RATERS[0][i]['cat'])==g and len({R[i]['q1'] for R in RATERS})==1), sum(1 for i in range(60) if grp(RATERS[0][i]['cat'])==g)) for g in ('L13','L46','LLM','IND','GEN')}
CONF={g:[sum(R[i]['conf'] for i in range(60) if grp(R[i]['cat'])==g)/sum(1 for i in range(60) if grp(R[i]['cat'])==g) for R in RATERS[1:]][0] for g in ('L13','L46','LLM','IND','GEN')}
if __name__=='__main__':
    for i,p in enumerate(PR): print('R%d'%(i+1),p)
    print('pair',PAIR,AGREE); print('unanimous',UN); print('conf r2,r3',CONF)
