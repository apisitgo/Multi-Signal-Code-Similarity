# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 -- Armstrong Number
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    num = 0
    num = int(tokens[0])
    digits_str = str(num)
    width = len(digits_str)
    accum = 0
    val = 0

    for ch in digits_str:
        power = 1
        val = int(ch)
        for k in range(width):
            power = power * val
        accum += power

    is_armstrong = (accum == num)
    print("Armstrong" if is_armstrong else "Not armstrong")


if __name__ == "__main__":
    main()
