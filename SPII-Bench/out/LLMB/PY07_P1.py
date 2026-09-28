# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Power
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def power(base, exponent):
    result = 1
    while exponent > 0:
        result = result * base
        exponent -= 1
    return result


def main():
    tokens = sys.stdin.read().split()
    base, exponent = int(tokens[0]), int(tokens[1])
    print(power(base, exponent))


if __name__ == "__main__":
    main()
