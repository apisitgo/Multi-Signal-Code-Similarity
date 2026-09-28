# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 — Power (a^b)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a, b = map(int, input().split())
    res = 1
    for i in range(b):
        res = res * a
    print(res)


if __name__ == "__main__":
    main()
