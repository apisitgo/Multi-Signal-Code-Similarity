# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 -- Armstrong Number
# Student : <student id> <full name>
# ==============================================================
import sys


def digit_power(val, width):
    return val ** width


def armstrong_total(digits_str, width):
    return sum(digit_power(int(ch), width) for ch in digits_str)


def is_armstrong(num):
    digits_str = str(num)
    width = len(digits_str)
    if armstrong_total(digits_str, width) != num:
        return False
    return True


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])

    verdict = "Not armstrong"
    if is_armstrong(num):
        verdict = "Armstrong"
    print(verdict)


if __name__ == "__main__":
    main()
