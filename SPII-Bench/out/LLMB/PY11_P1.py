# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

THRESHOLDS = [(80, "A"), (70, "B"), (60, "C"), (50, "D")]


def letter_grade(score):
    for cutoff, letter in THRESHOLDS:
        if score >= cutoff:
            return letter
    return "F"


def main():
    tokens = sys.stdin.read().split()
    print(letter_grade(int(tokens[0])))


if __name__ == "__main__":
    main()
