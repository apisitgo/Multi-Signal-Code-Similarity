# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


def main():
    tokens = sys.stdin.read().split()
    first = int(tokens[0])
    second = int(tokens[1])
    print(gcd(first, second))


if __name__ == "__main__":
    main()
