# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>

import sys


def main():
    data = sys.stdin.read().split()

    a = int(data[0]); b = int(data[1])

    # Euclid's algorithm: keep replacing (a, b) by (b, a mod b)
    while b != 0 :
        t = a % b
        a = b
        b = t

    print(a)   # a now holds the gcd


if __name__ == "__main__":
    main()
