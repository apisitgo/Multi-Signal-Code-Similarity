# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read the number
    n = int(input())

    # Calculate sum of digits
    total = 0
    while n > 0:
        digit = n % 10
        total = total + digit
        n = n // 10

    print(total)


if __name__ == "__main__":
    main()
