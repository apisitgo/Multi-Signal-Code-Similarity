# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read the number
    n = int(input())

    # Print multiplication table
    for i in range(1, 13):
        result = n * i
        print(f"{n} x {i} = {result}")


if __name__ == "__main__":
    main()
