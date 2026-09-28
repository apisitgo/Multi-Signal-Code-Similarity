# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #7 -- GCD (Greatest Common Divisor)
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    # two numbers to find the GCD of
    data = sys.stdin.read().split()
    a = int(data[0])
    b = int(data[1])

    # classic Euclid's algorithm
    while b != 0:
        t = a % b
        a = b
        b = t

    print(a)


if __name__ == "__main__":
    main()
