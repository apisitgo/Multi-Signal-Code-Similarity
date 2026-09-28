# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def num(t):
    f = float(t)
    return int(f) if f == int(f) else f


def second(xs):
    u = sorted(set(xs), reverse=True)
    return u[1] if len(u) > 1 else None


def main():
    d = sys.stdin.read().split()
    n = int(d[0])
    xs = [num(t) for t in d[1:1 + n]]
    s = second(xs)
    if s is None:
        print("No second largest")
    else:
        print(f"Second largest = {s}")


if __name__ == "__main__":
    main()
