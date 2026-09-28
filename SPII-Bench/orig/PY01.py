# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 — Even or Odd
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    print("Even" if n % 2 == 0 else "Odd")


if __name__ == "__main__":
    main()
