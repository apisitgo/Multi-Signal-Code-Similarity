# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    total = sum(int(d) for d in str(n))
    print(total)
    pass


if __name__ == "__main__":
    main()
