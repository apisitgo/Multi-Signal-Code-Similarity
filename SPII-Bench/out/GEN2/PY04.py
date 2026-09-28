# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 — Sum of Digits
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = abs(int(data[0]))
    total = 0
    while n > 0:
        total += n % 10
        n //= 10
    print(total)


if __name__ == "__main__":
    main()
