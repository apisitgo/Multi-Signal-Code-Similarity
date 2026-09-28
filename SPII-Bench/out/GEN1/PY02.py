# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    score = int(input())
    if score >= 50:
        print("Pass")
    else:
        print("Fail")
    pass


if __name__ == "__main__":
    main()
