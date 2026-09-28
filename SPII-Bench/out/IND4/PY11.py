# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    if n >= 80:
        print("A")
    elif n >= 70:
        print("B")
    elif n >= 60:
        print("C")
    elif n >= 50:
        print("D")
    else:
        print("F")


if __name__ == "__main__":
    main()
