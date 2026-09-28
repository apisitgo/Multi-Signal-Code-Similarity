# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a, b = map(int, input().split())
    while b != 0:
        a, b = b, a % b
    print(a)


if __name__ == "__main__":
    main()
