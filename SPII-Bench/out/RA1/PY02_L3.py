# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 -- Pass or Fail
# Student : <student id> <full name>
# ==============================================================
import sys

PASS_MARK = 50


def main():
    tokens = sys.stdin.read().split()
    raw_mark = tokens[0]
    mark = int(raw_mark)

    print("Pass" if mark >= PASS_MARK else "Fail")


if __name__ == "__main__":
    main()
