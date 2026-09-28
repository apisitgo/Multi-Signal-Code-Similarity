# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 -- Sum of Digits
# Student : <student id> <full name>
# ==============================================================
import sys


def digit_sum(remaining):
    if remaining <= 0:
        return 0
    remaining, digit = divmod(remaining, 10)
    return digit + digit_sum(remaining)


def main():
    tokens = sys.stdin.read().split()
    raw_value = int(tokens[0])
    remaining = abs(raw_value)

    print(digit_sum(remaining))


if __name__ == "__main__":
    main()
