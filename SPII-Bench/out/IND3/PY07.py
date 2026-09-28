# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 — Power (a^b)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def power(a, b):
    r = 1
    for _ in range(b):
        r *= a
    return r


def main():
    a, b = map(int, sys.stdin.read().split()[:2])
    print(power(a, b))


if __name__ == "__main__":
    main()
