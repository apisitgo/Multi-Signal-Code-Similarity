# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def dsum(n):
    n = abs(n)
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s


def main():
    n = int(sys.stdin.read().split()[0])
    print(dsum(n))


if __name__ == "__main__":
    main()
