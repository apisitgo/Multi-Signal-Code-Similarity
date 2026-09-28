# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 — Power (a^b)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    a = int(data[0])
    b = int(data[1])

    result = 1
    i = 0
    while i < b:
        result = result * a
        i = i + 1

    print(result)


if __name__ == "__main__":
    main()
