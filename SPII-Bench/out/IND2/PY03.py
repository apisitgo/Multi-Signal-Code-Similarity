# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    a = int(data[0])
    b = int(data[1])

    # Euclid's algorithm using a while loop
    while b != 0:
        a, b = b, a % b

    print(a)


if __name__ == "__main__":
    main()
