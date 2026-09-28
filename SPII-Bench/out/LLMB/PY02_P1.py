# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 — Pass or Fail
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

PASS_MARK = 50


def evaluate(points):
    return "Pass" if points >= PASS_MARK else "Fail"


def main():
    tokens = sys.stdin.read().split()
    points = int(tokens[0])
    print(evaluate(points))


if __name__ == "__main__":
    main()
