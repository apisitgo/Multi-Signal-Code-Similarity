# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 — Even or Odd
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def is_even(n):
    return n % 2 == 0


def main():
    n = int(sys.stdin.read().split()[0])
    print("Even" if is_even(n) else "Odd")


if __name__ == "__main__":
    main()
