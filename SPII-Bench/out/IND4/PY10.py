# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a = sys.stdin.read().split()
    n = int(a[0])
    b = [int(x) for x in a[1:1 + n]]
    b = sorted(set(b))
    print("Second largest =", b[-2])


if __name__ == "__main__":
    main()
