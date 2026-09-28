# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>

import sys


def main():
    vals = sys.stdin.read().split()

    x = int(vals[0]); y = int(vals[1])

    # Euclid's algorithm: keep replacing (x, y) by (y, x mod y)
    while y != 0 :
        rem = x % y
        x = y
        y = rem

    print(x)   # x now holds the gcd


if __name__ == "__main__":
    main()
