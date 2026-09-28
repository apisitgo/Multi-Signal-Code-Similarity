# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 -- Even or Odd
# Student : <student id> <full name>
# ==============================================================
import sys


def is_even(num):
    return num % 2 == 0


def main():
    tokens = sys.stdin.read().split()
    raw_token = tokens[0]
    num = 0
    num = int(raw_token)

    if is_even(num):
        result = "Even"
    else:
        result = "Odd"
    print(result)


if __name__ == "__main__":
    main()
