# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 -- Pass or Fail
# Student : <student id> <full name>
# ==============================================================
import sys

PASS_MARK = 50


def is_failing(mark):
    if mark < PASS_MARK:
        return True
    return False


def main():
    tokens = sys.stdin.read().split()
    raw_mark = tokens[0]
    mark = int(raw_mark)

    verdict = "Pass"
    if is_failing(mark):
        verdict = "Fail"
    print(verdict)


if __name__ == "__main__":
    main()
