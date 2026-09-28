# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 -- Pass or Fail
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    mark = int(tokens[0])

    print("Pass" if mark >= 50 else "Fail")


if __name__ == "__main__":
    main()
