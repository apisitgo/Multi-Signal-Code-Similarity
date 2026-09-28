# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def is_arm(n):
    if n < 0:
        return False
    ds = str(n)
    k = len(ds)
    return sum(int(d) ** k for d in ds) == n


def main():
    n = int(sys.stdin.read().split()[0])
    print("Armstrong" if is_arm(n) else "Not armstrong")


if __name__ == "__main__":
    main()
