# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def grade(s):
    return "Pass" if s >= 50 else "Fail"


def main():
    s = int(sys.stdin.read().split()[0])
    print(grade(s))


if __name__ == "__main__":
    main()
