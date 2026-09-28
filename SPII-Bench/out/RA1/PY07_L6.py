# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 -- Power (a^b)
# Student : <student id> <full name>
# ==============================================================
import sys

IDENTITY = 1


def power(base, exp):
    if exp <= 0:
        return IDENTITY
    return base * power(base, exp - 1)


def main():
    tokens = sys.stdin.read().split()
    base, exp = int(tokens[0]), int(tokens[1])

    print(power(base, exp))


if __name__ == "__main__":
    main()
