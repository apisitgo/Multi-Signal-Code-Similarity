# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input("Enter n: "))

    numbers = []
    i = 1
    while i <= n:
        numbers.append(str(i))
        i = i + 1

    print(" ".join(numbers))


if __name__ == "__main__":
    main()
