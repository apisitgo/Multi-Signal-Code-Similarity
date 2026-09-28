# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input("Enter a number: "))

    i = 1
    while i <= 12:
        print(str(n) + " x " + str(i) + " = " + str(n * i))
        i = i + 1


if __name__ == "__main__":
    main()
