# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(sys.stdin.read().split()[0])
    print(" ".join(str(i) for i in range(1, n + 1)))


if __name__ == "__main__":
    main()
