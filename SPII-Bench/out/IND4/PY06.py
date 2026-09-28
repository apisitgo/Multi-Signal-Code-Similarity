# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    for i in range(1, 13):
        print(n, "x", i, "=", n * i)


if __name__ == "__main__":
    main()
