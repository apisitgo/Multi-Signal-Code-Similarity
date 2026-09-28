import json, matplotlib
matplotlib.use('Agg'); import matplotlib.pyplot as plt
O=json.load(open('data/bench_results.json'))
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':8,'axes.spines.top':False,'axes.spines.right':False,'axes.edgecolor':'#555','axes.grid':True,'grid.color':'#e3e3e3','grid.linewidth':0.6})
M=[('SPII-v1','SPII-v1','#2a78d6','o','-'),('SPII-v2 + starter subtraction','SPII-v2 + starter','#eb6834','s','--'),('JPlag','JPlag 6.2','#1baf7a','^','-.'),('Dolos + ignore starter','Dolos + ignore','#eda100','D',':')]
C=['L1','L2','L3','L4','L5','L6','LLM-P1','LLM-P2','LLM-P3']; lab=['L1','L2','L3','L4','L5','L6','LLM\nP1','LLM\nP2','LLM\nP3']
mm=1/25.4
fig,axs=plt.subplots(1,2,figsize=(174*mm,68*mm),sharey=True)
for ax,lang,title in zip(axs,['python','c'],['Python (15 problems)','C (15 problems)']):
    for k,l,c,mk,ls in M:
        v=[O['percat'][lang][x][k] for x in C]
        ax.plot(range(6),v[:6],color=c,marker=mk,ls=ls,lw=1.8,ms=5,label=l,mec='white',mew=0.7)
        ax.plot(range(6,9),v[6:],color=c,marker=mk,ls=ls,lw=1.8,ms=5,mec='white',mew=0.7)
    ax.axhline(0.5,color='#888',lw=1,ls=(0,(2,2))); ax.axvspan(5.5,8.5,color='#f2f2f2',zorder=0)
    ax.set_xticks(range(9)); ax.set_xticklabels(lab,fontsize=7); ax.set_title(title,fontsize=8.5,loc='left'); ax.set_ylim(0,1.02); ax.set_xlim(-0.4,8.4)
axs[0].set_ylabel('AUROC (category vs. independent)')
axs[1].text(8.3,0.52,'chance',fontsize=7,color='#555',ha='right')
axs[0].legend(frameon=False,fontsize=7,loc='lower left')
fig.tight_layout(); fig.savefig('fig/fig5_bench.png',dpi=600); fig.savefig('fig/fig5_bench.pdf')
