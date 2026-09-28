# SPII-Bench obfuscation protocol (Faidhi & Robinson, 1987 levels; cumulative)

You play a student who copied the ORIGINAL program from a classmate and disguises it.
Produce six versions L1..L6 of the ORIGINAL. Each level applies its own change AND all changes of the lower levels
(L3 = L1 + L2 + L3 changes, etc.). Apply the changes thoroughly but naturally, as a student would.

- L1 Comments and layout: change indentation style/width, blank lines, spacing around operators, line breaks;
  add, remove or reword comments. No change to code tokens.
- L2 Identifiers: L1 + rename every student-defined identifier (variables, helper functions, parameters, constants).
- L3 Declarations: L2 + change declarations: move declarations to other places, split or merge declarations,
  declare-then-assign vs initialise, add redundant variables or constants, change harmless types (int/long, int/float where output stays identical).
- L4 Program modules: L3 + change modularisation: extract parts into new helper functions, inline existing helpers,
  merge or split functions.
- L5 Program statements: L4 + change statements: reorder independent statements, replace statements with equivalent
  forms (for <-> while, x += 1 <-> x = x + 1, split or combine expressions, equivalent library calls, different but
  equivalent input parsing).
- L6 Control logic: L5 + restructure control flow while keeping the same algorithm and output: invert conditions,
  if/else chains <-> nested ifs or switch / dictionary lookup, loops <-> recursion where natural, early returns/breaks,
  flag variables.

Rules
1. Output text must stay byte-identical in content (same messages, same formatting) - a student keeps the output the grader expects.
2. Keep the starter skeleton recognisable: the header comment block may be reformatted only at L1+ like any comment;
   keep `main` / the `if __name__ == "__main__":` guard (Python) and `int main(void)` (C).
3. Every version must pass the unit's tests: `cd /home/claude/a1/bench && python3 harness.py <UID> <file>` must print "ok": true.
4. Do not look at any other solution of the problem (never open /home/claude/a1/bench/out/IND*, GEN*, LLM*) — you only copy the ORIGINAL.
