# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>

import sys


def gcd_of(x, y):
    # Euclid's algorithm with tuple assignment
    while y:
        x, y = y, x % y
    return x


def main():
    x, y = map(int, sys.stdin.read().split()[:2])
    answer = gcd_of(x, y)
    print(answer)   # the gcd


if __name__ == "__main__":
    main()
