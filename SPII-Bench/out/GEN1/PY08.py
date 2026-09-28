# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    s = str(n)
    num_digits = len(s)
    total = sum(int(d) ** num_digits for d in s)
    if total == n:
        print("Armstrong")
    else:
        print("Not armstrong")


if __name__ == "__main__":
    main()
