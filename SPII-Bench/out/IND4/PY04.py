# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    print(res)


if __name__ == "__main__":
    main()
