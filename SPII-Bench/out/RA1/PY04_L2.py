# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 -- Sum of Digits
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    remaining = abs(int(tokens[0]))
    total = 0

    while remaining > 0:
        total += remaining % 10
        remaining //= 10

    print(total)


if __name__ == "__main__":
    main()
