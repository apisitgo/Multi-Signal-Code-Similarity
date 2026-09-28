# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def num(t):
    f = float(t)
    return int(f) if f == int(f) else f


def fmt(x):
    if x == int(x):
        return str(int(x))
    return f"{x:.2f}"


def main():
    d = sys.stdin.read().split()
    n = int(d[0])
    xs = [num(t) for t in d[1:1 + n]]
    if not xs:
        return
    s = sum(xs)
    print(f"Sum = {fmt(s)}")
    print(f"Average = {fmt(s / len(xs))}")
    print(f"Max = {fmt(max(xs))}")
    print(f"Min = {fmt(min(xs))}")


if __name__ == "__main__":
    main()
