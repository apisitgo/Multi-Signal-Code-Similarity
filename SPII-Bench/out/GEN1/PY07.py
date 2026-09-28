# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 — Power (a^b)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a, b = map(int, input().split())
    result = 1
    for _ in range(b):
        result *= a
    print(result)
    pass


if __name__ == "__main__":
    main()
