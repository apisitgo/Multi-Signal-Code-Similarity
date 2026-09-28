# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 -- Power (a^b)
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    base = int(tokens[0])
    exp = int(tokens[1])
    result = 1

    for step in range(exp):
        result *= base

    print(result)


if __name__ == "__main__":
    main()
