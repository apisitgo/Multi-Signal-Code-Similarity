# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #1 — Even or Odd
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    number = int(input("Enter an integer: "))
    if number % 2 == 0:
        print("Even")
    else:
        print("Odd")


if __name__ == "__main__":
    main()
