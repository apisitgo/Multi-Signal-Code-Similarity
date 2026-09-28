# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    score = int(data[0])
    if score >= 50:
        print("Pass")
    else:
        print("Fail")


if __name__ == "__main__":
    main()
