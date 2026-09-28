# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def is_armstrong(number):
    digits = str(number)
    width = len(digits)
    return sum(int(c) ** width for c in digits) == number


def main():
    tokens = sys.stdin.read().split()
    number = int(tokens[0])
    print("Armstrong" if is_armstrong(number) else "Not armstrong")


if __name__ == "__main__":
    main()
