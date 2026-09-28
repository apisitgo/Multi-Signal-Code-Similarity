# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input("Enter a positive integer: "))
    total = 0
    temp = n
    while temp > 0:
        digit = temp % 10
        total = total + digit
        temp = temp // 10

    print(total)


if __name__ == "__main__":
    main()
