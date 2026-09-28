# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 -- GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ==============================================================
import sys


def gcd(x, y):
    rem = 0
    while y != 0:
        rem = x % y
        x = y
        y = rem
    return x


def main():
    tokens = sys.stdin.read().split()
    x = 0
    y = 0
    x = int(tokens[0])
    y = int(tokens[1])

    print(gcd(x, y))


if __name__ == "__main__":
    main()
