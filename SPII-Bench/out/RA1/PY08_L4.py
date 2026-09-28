# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 -- Armstrong Number
# Student : <student id> <full name>
# ==============================================================
import sys


def digit_power(val, width):
    power = 1
    for k in range(width):
        power = power * val
    return power


def armstrong_total(digits_str, width):
    accum = 0
    for ch in digits_str:
        val = int(ch)
        accum += digit_power(val, width)
    return accum


def main():
    tokens = sys.stdin.read().split()
    num = 0
    num = int(tokens[0])
    digits_str = str(num)
    width = len(digits_str)

    is_armstrong = (armstrong_total(digits_str, width) == num)
    print("Armstrong" if is_armstrong else "Not armstrong")


if __name__ == "__main__":
    main()
