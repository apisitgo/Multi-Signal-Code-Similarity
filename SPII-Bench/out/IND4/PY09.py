# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    res = []
    for i in range(1, n + 1):
        res.append(str(i))
    print(" ".join(res))


if __name__ == "__main__":
    main()
