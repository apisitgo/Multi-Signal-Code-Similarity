# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 -- GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ==============================================================
import sys


def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


def main():
    tokens = sys.stdin.read().split()
    x = 0
    y = 0
    x, y = int(tokens[0]), int(tokens[1])

    print(gcd(x, y))


if __name__ == "__main__":
    main()
