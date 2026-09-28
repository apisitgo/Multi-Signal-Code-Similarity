import json, numpy as np, matplotlib
matplotlib.use('Agg'); import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch
O=json.load(open('data/results.json')); RT=json.load(open('data/runtime.json'))
P=json.load(open('data/pairs.json')); V2={int(k):v for k,v in json.load(open('data/v2_out.json')).items()}
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':8,'axes.spines.top':False,'axes.spines.right':False,
 'axes.edgecolor':'#555','axes.labelcolor':'#222','xtick.color':'#444','ytick.color':'#444','axes.grid':True,'grid.color':'#e3e3e3','grid.linewidth':0.6})
C={'SPII-v1':'#2a78d6','SPII-v2 (hand)':'#eb6834','JPlag':'#1baf7a','Dolos':'#eda100'}
MK={'SPII-v1':'o','SPII-v2 (hand)':'s','JPlag':'^','Dolos':'D'}
LS={'SPII-v1':'-','SPII-v2 (hand)':'--','JPlag':'-.','Dolos':':'}
LAB={'SPII-v1':'SPII-v1','SPII-v2 (hand)':'SPII-v2','JPlag':'JPlag 6.2','Dolos':'Dolos'}
mm=1/25.4
# Fig 2 per-level AUROC
L=['L1','L2','L3','L4','L5','L6']
fig,ax=plt.subplots(figsize=(120*mm,70*mm))
for m in C:
    ax.plot(L,[O['levels'][l][m] for l in L],color=C[m],marker=MK[m],ls=LS[m],lw=2,ms=6,label=LAB[m],mec='white',mew=0.8)
ax.axhline(0.5,color='#888',lw=1,ls=(0,(2,2))); ax.text(5.05,0.51,'chance',color='#555',fontsize=7,ha='right',va='bottom')
ax.set_ylim(0,1.02); ax.set_ylabel('AUROC (level vs. independent)'); ax.set_xlabel('Faidhi–Robinson obfuscation level')
ax.legend(frameon=False,ncol=4,loc='lower left',fontsize=7)
fig.tight_layout(); fig.savefig('fig/fig2_levels.png',dpi=600); fig.savefig('fig/fig2_levels.pdf')
# Fig 3 score distributions IR-Plag
groups={'Independent':[V2[p['id']]['overall'] for p in P if p['ds']=='irplag' and p['label']==0]}
for l in L: groups[l]=[V2[p['id']]['overall'] for p in P if p['ds']=='irplag' and p['level']==l]
fig,ax=plt.subplots(figsize=(120*mm,68*mm))
bp=ax.boxplot(list(groups.values()),widths=0.55,patch_artist=True,showfliers=True,flierprops=dict(marker='.',ms=3,mfc='#999',mec='#999'),medianprops=dict(color='#111',lw=1.4))
for i,b in enumerate(bp['boxes']):
    b.set_facecolor('#86b6ef' if i==0 else '#e8e8e8'); b.set_edgecolor('#555')
ax.set_xticks(range(1,8)); ax.set_xticklabels(list(groups.keys()))
med=np.median(groups['Independent']); ax.axhline(med,color='#1c5cab',lw=1,ls=(0,(3,2)))
ax.text(1.35,med-0.045,f'independent median {med:.2f}',color='#1c5cab',fontsize=7,ha='left')
ax.set_ylabel('SPII-v2 similarity (hand-weighted)'); ax.set_ylim(0,1.05)
ax.set_xlabel('Pair type (IR-Plag, n = %d independent pairs)'%len(groups['Independent']))
fig.tight_layout(); fig.savefig('fig/fig3_dist.png',dpi=600); fig.savefig('fig/fig3_dist.pdf')
# Fig 4 runtime
ns=sorted(int(k) for k in RT); K={'SPII-v1':'v1','SPII-v2 (hand)':'v2','JPlag':'jplag','Dolos':'dolos'}
fig,ax=plt.subplots(figsize=(100*mm,65*mm))
for m in C:
    ys=[RT[str(n)][K[m]] for n in ns]
    ax.plot(ns,ys,color=C[m],marker=MK[m],ls=LS[m],lw=2,ms=6,label=LAB[m],mec='white',mew=0.8)
    ax.annotate(f'{ys[-1]:.0f} s' if ys[-1]>=10 else f'{ys[-1]:.1f} s',(ns[-1],ys[-1]),xytext=(5,{'SPII-v1':0,'SPII-v2 (hand)':-5,'JPlag':5,'Dolos':0}[m]),textcoords='offset points',fontsize=7,color='#333',va='center')
ax.set_yscale('log'); ax.set_xticks(ns); ax.set_xlim(40,235); ax.set_xlabel('Submissions per assignment (all pairs)'); ax.set_ylabel('Wall-clock time (s, log scale)')
ax.legend(frameon=False,fontsize=7,loc='upper left')
fig.tight_layout(); fig.savefig('fig/fig4_runtime.png',dpi=600); fig.savefig('fig/fig4_runtime.pdf')
# Fig 1 pipeline
fig,ax=plt.subplots(figsize=(174*mm,66*mm)); ax.set_xlim(0,180); ax.set_ylim(0,66); ax.axis('off')
def box(x,y,w,h,t,fc='white',ec='#555'):
    ax.add_patch(FancyBboxPatch((x,y),w,h,boxstyle='round,pad=0,rounding_size=2',fc=fc,ec=ec,lw=0.9))
    ax.text(x+w/2,y+h/2,t,ha='center',va='center',fontsize=6.5,color='#111',linespacing=1.3)
def arr(x1,y1,x2,y2): ax.annotate('',(x2,y2),(x1,y1),arrowprops=dict(arrowstyle='-|>',color='#555',lw=0.9,shrinkA=0,shrinkB=0))
box(1,24,22,14,'Two\nsubmissions\n(A, B)')
box(29,22,30,18,'Language-aware\nscanner:\ndrop comments,\nmask strings',fc='#f4f4f4')
sig=[('Token 3-grams\n(identifiers → V)',46),('Winnowed char\n5-grams (w = 4)',33),('Normalised\nline set',20),('Edit-distance\nratio',7)]
for t,y in sig: box(69,y,32,11,t)
arr(23,31,29,31)
for t,y in sig: arr(59,31,69,y+5.5)
ax.text(85,61,'one similarity per representation',ha='center',fontsize=6.5,color='#555')
box(111,19,34,24,'Fusion\nhand .35/.30/.20/.15\nmean · max · LR',fc='#fdebe3',ec='#eb6834')
for t,y in sig: arr(101,y+5.5,111,31)
box(153,35,26,14,'Problem-aware\nrobust z',fc='#f4f4f4')
box(153,12,26,16,'Ranked pairs\n+ per-signal\nevidence')
arr(145,34,153,42); arr(166,35,166,28)
fig.savefig('fig/fig1_pipeline.png',dpi=600,bbox_inches='tight'); fig.savefig('fig/fig1_pipeline.pdf',bbox_inches='tight')
print('ok')
