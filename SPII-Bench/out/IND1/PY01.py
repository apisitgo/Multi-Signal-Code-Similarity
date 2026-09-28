# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 — Even or Odd
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read a number from input
    n = int(input())

    # Check if it's even or odd
    if n % 2 == 0:
        print("Even")
    else:
        print("Odd")


if __name__ == "__main__":
    main()
