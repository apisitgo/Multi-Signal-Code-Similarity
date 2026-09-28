# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 -- GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    x = int(tokens[0])
    y = int(tokens[1])

    while y != 0:
        rem = x % y
        x = y
        y = rem

    print(x)


if __name__ == "__main__":
    main()
