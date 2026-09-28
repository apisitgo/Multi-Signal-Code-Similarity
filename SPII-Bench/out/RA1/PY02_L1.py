# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #1 -- Pass or Fail
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    # read the score from stdin
    data = sys.stdin.read().split()
    score = int(data[0])

    # 50 or above counts as a pass
    print("Pass" if score >= 50 else "Fail")


if __name__ == "__main__":
    main()
