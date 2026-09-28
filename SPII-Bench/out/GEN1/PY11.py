# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    score = int(input())
    if 80 <= score <= 100:
        print("A")
    elif 70 <= score < 80:
        print("B")
    elif 60 <= score < 70:
        print("C")
    elif 50 <= score < 60:
        print("D")
    else:
        print("F")
    pass


if __name__ == "__main__":
    main()
