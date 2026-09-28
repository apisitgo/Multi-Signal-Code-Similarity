# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 — Even or Odd
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def parity_label(value):
    if value & 1:
        return "Odd"
    return "Even"


def main():
    tokens = sys.stdin.read().split()
    number = int(tokens[0])
    print(parity_label(number))


if __name__ == "__main__":
    main()
