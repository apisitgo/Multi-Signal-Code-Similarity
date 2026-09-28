# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read two numbers
    line = input().split()
    a = int(line[0])
    b = int(line[1])

    # Use Euclid's algorithm to find GCD
    while b != 0:
        temp = b
        b = a % b
        a = temp

    # a now contains the GCD
    print(a)


if __name__ == "__main__":
    main()
