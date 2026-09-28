# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 -- Sum of Digits
# Student : <student id> <full name>
# ==============================================================
import sys


def digit_sum(remaining):
    total = 0
    while remaining > 0:
        remaining, digit = divmod(remaining, 10)
        total = total + digit
    return total


def main():
    tokens = sys.stdin.read().split()
    raw_value = int(tokens[0])
    remaining = abs(raw_value)

    print(digit_sum(remaining))


if __name__ == "__main__":
    main()
