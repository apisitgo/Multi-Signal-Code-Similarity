# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 -- Even or Odd
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])

    print("Even" if num % 2 == 0 else "Odd")


if __name__ == "__main__":
    main()
