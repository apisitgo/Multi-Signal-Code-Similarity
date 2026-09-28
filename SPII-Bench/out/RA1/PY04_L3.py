# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 -- Sum of Digits
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    raw_value = int(tokens[0])
    remaining = 0
    remaining = abs(raw_value)
    total = 0
    digit = 0

    while remaining > 0:
        digit = remaining % 10
        total += digit
        remaining //= 10

    print(total)


if __name__ == "__main__":
    main()
