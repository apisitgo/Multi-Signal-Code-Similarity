# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read n
    n = int(input())

    # Print numbers 1 to n separated by spaces
    result = ""
    for i in range(1, n + 1):
        if i == 1:
            result = str(i)
        else:
            result = result + " " + str(i)

    print(result)


if __name__ == "__main__":
    main()
