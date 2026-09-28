// Harness: runs SPII-v1 similarity exactly as implemented in similarity.service.ts
const { SimilarityService } = require('./svc.js');
const fs = require('fs');
const svc = new SimilarityService(null);
const [,, listFile, outFile] = process.argv;
const pairs = JSON.parse(fs.readFileSync(listFile, 'utf8'));
const cache = new Map();
function prep(p) {
  if (cache.has(p)) return cache.get(p);
  const code = fs.readFileSync(p, 'utf8');
  const normText = svc.normalizeText(code);
  const r = { normText, tok: svc.tokenShingles(code), kg: svc.kgrams(normText), lines: svc.lineSet(code) };
  cache.set(p, r); return r;
}
const out = [];
const t0 = process.hrtime.bigint();
for (const pr of pairs) {
  const A = prep(pr.a), B = prep(pr.b);
  const token = svc.jaccard(A.tok, B.tok), fingerprint = svc.jaccard(A.kg, B.kg), lineset = svc.jaccard(A.lines, B.lines), text = svc.textSim(A.normText, B.normText);
  const overall = Math.round((token * 0.35 + fingerprint * 0.3 + lineset * 0.2 + text * 0.15) * 100);
  out.push({ id: pr.id, token, fingerprint, lineset, text, overall });
}
const ms = Number(process.hrtime.bigint() - t0) / 1e6;
fs.writeFileSync(outFile, JSON.stringify({ ms, results: out }));
console.log('pairs', out.length, 'ms', ms.toFixed(1));
