# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a = sys.stdin.read().split()
    n = int(a[0])
    b = [int(x) for x in a[1:1 + n]]
    s = sum(b)
    print("Sum =", s)
    print("Average = %.2f" % (s / n))
    print("Max =", max(b))
    print("Min =", min(b))


if __name__ == "__main__":
    main()
