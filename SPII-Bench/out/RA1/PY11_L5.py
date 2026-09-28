# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 -- Letter Grade
# Student : <student id> <full name>
# ==============================================================
import sys
import bisect

CUTOFFS = [0, 50, 60, 70, 80]
LETTERS = ["F", "D", "C", "B", "A"]


def letter_for(mark):
    idx = bisect.bisect_right(CUTOFFS, mark) - 1
    if idx < 0:
        idx = 0
    return LETTERS[idx]


def main():
    tokens = sys.stdin.read().split()
    mark = int(tokens[0])

    print(letter_for(mark))


if __name__ == "__main__":
    main()
