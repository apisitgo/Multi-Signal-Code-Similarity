# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 — Power (a^b)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read a and b
    line = input().split()
    a = int(line[0])
    b = int(line[1])

    # Calculate a^b by multiplying
    result = 1
    for i in range(b):
        result = result * a

    print(result)


if __name__ == "__main__":
    main()
