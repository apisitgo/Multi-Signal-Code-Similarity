import numpy as np
from scipy import stats
from sklearn.metrics import roc_auc_score, average_precision_score, roc_curve
rng = np.random.default_rng(20260927)

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


