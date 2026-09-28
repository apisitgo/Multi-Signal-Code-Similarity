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

    print("Even" if is_even(num) else "Odd")


if __name__ == "__main__":
    main()
