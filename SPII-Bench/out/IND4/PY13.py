# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a = sys.stdin.read().split()
    n = int(a[0])
    b = [int(x) for x in a[1:1 + n]]
    p = 0
    for x in b:
        if x >= 50:
            p += 1
    print("Passed =", p)
    print("Failed =", n - p)
    print("Average = %.2f" % (sum(b) / n))
    print("Highest =", max(b))


if __name__ == "__main__":
    main()
