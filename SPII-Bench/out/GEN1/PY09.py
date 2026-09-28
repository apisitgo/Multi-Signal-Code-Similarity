# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    print(' '.join(str(i) for i in range(1, n + 1)))
    pass


if __name__ == "__main__":
    main()
