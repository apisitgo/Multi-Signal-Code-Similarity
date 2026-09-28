# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read the number
    n = int(input())

    # Convert to string
    n_str = str(n)
    num_digits = len(n_str)

    # Calculate sum of digits each raised to power of digit count
    total = 0
    for digit_char in n_str:
        digit = int(digit_char)
        total += digit ** num_digits

    # Check if Armstrong
    if total == n:
        print("Armstrong")
    else:
        print("Not Armstrong")


if __name__ == "__main__":
    main()
