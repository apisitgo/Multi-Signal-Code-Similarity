# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read the grade
    grade = int(input())

    # Check if pass or fail
    if grade >= 50:
        print("Pass")
    else:
        print("Fail")


if __name__ == "__main__":
    main()
