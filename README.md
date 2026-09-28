# Replication package — SPII multi-signal similarity evaluation

## Public Java benchmarks
1. Clone https://github.com/oscarkarnalim/sourcecodeplagiarismdataset (IR-Plag, Apache-2.0); download ConPlag from https://doi.org/10.5281/zenodo.7332748 (CC BY 4.0).
2. scripts/build_data.py -> pair lists; spii-v1-harness (unmodified production logic, `npx tsc svc.ts` then `node v1.js in.json out.json`); scripts/run_v2.py; scripts/run_baselines.py (JPlag 6.2.0, Dolos CLI); scripts/analysis.py; scripts/runtime.py; scripts/figs.py.

## SPII-Bench (30 problems, 750 files)
- SPII-Bench/tasks/<UID>/problem.md, starter.{py,c}; units.json holds statements and the 4 test cases per problem.
- SPII-Bench/orig: literal translations of the instructor reference solutions.
- SPII-Bench/out/RA1, RA2: Faidhi–Robinson levels L1–L6 (cumulative) per PROTOCOL_obfuscation.md.
- SPII-Bench/out/LLMA, LLMB: LLM rewrites for requests P1–P3.
- SPII-Bench/out/IND1–IND4: independent solutions (student personas); GEN1–GEN2: plain LLM solutions.
- harness.py: SPII checker (collapse_ws + must). 748/750 files pass; IND1/PY08 and IND2/PY08 differ only in capitalisation.
- scripts/bench_eval.py, bench_jplag_t.py, figs_bench.py -> data/bench_*.json, figures/fig5_bench.*
Environment: 2 vCPU Xeon 2.1 GHz, 7 GB RAM, OpenJDK 21, Node 22, Python 3, gcc, scikit-learn 1.8, RapidFuzz 3.14.

## Human audit (60 pairs, 2 raters)
- audit/round1-instructions-and-sheet.xlsx (rater 1), audit/round2-instructions-and-sheet.xlsx (rater 2; revised instructions, practice pairs, re-shuffled order); audit/key_round2.json maps round-2 items to pair ids and round-1 items.
- data/audit_r1.json, audit_r2.json: anonymous judgements in round-1 item order (q1 = derived?, q2 = same behaviour?, conf and evidence for rater 2).
- scripts/audit_stats.py: per-rater counts, Cohen's kappa with labels and between raters (Table 10).
