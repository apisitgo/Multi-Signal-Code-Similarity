# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 -- Power (a^b)
# Student : <student id> <full name>
# ==============================================================
import sys

IDENTITY = 1


def power(base, exp):
    result = IDENTITY
    step = 0
    while step < exp:
        result = result * base
        step += 1
    return result


def main():
    tokens = sys.stdin.read().split()
    base, exp = int(tokens[0]), int(tokens[1])

    print(power(base, exp))


if __name__ == "__main__":
    main()
