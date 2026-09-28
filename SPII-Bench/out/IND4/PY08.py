# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    s = input().strip()
    n = int(s)
    k = len(s)
    res = 0
    for c in s:
        res += int(c) ** k
    if res == n:
        print("Armstrong")
    else:
        print("Not armstrong")


if __name__ == "__main__":
    main()
