# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 — GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    a, b = abs(int(data[0])), abs(int(data[1]))
    # Euclid's algorithm
    while b != 0:
        a, b = b, a % b
    print(a)


if __name__ == "__main__":
    main()
