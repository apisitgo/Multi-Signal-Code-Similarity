# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def num(t):
    f = float(t)
    return int(f) if f == int(f) else f


def summary(xs):
    p = sum(1 for x in xs if x >= 50)
    avg = sum(xs) / len(xs) if xs else 0
    hi = max(xs) if xs else 0
    return p, len(xs) - p, avg, hi


def main():
    d = sys.stdin.read().split()
    n = int(d[0])
    xs = [num(t) for t in d[1:1 + n]]
    p, f, avg, hi = summary(xs)
    print(f"Passed = {p}")
    print(f"Failed = {f}")
    print(f"Average = {avg:.2f}")
    print(f"Highest = {hi}")


if __name__ == "__main__":
    main()
