# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 -- Even or Odd
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    # read all whitespace-separated tokens from stdin
    data = sys.stdin.read().split()
    n = int(data[0])  # the number to test

    # decide even or odd and print the result
    print("Even" if n % 2 == 0 else "Odd")


if __name__ == "__main__":
    main()
