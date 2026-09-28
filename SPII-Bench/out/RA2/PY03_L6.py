# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>

import sys


def gcd_of(x, y):
    # recursive version of Euclid
    if not y:
        return x
    return gcd_of(y, x % y)


def main():
    x, y = map(int, sys.stdin.read().split()[:2])
    answer = gcd_of(x, y)
    print(answer)   # the gcd


if __name__ == "__main__":
    main()
