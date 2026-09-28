# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    digits = str(abs(n))
    k = len(digits)
    total = 0
    for ch in digits:
        total += int(ch) ** k
    if n >= 0 and total == n:
        print("Armstrong")
    else:
        print("Not armstrong")


if __name__ == "__main__":
    main()
