# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    score = int(input("Enter your score (0-100): "))
    if score >= 50:
        print("Pass")
    else:
        print("Fail")


if __name__ == "__main__":
    main()
