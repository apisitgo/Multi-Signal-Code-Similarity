# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 -- Power (a^b)
# Student : <student id> <full name>
# ==============================================================
import sys

IDENTITY = 1


def main():
    tokens = sys.stdin.read().split()
    base = 0
    exp = 0
    base = int(tokens[0])
    exp = int(tokens[1])
    result = IDENTITY

    for step in range(exp):
        result *= base

    print(result)


if __name__ == "__main__":
    main()
