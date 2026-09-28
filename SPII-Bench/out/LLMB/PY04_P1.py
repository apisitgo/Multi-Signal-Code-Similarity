# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def digit_sum(value):
    return sum(int(c) for c in str(abs(value)))


def main():
    tokens = sys.stdin.read().split()
    number = int(tokens[0])
    print(digit_sum(number))


if __name__ == "__main__":
    main()
