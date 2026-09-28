# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 -- Letter Grade
# Student : <student id> <full name>
# ==============================================================
import sys

GRADE_TABLE = {
    "A": 80,
    "B": 70,
    "C": 60,
    "D": 50,
}


def letter_for(mark):
    for letter, cutoff in GRADE_TABLE.items():
        if mark >= cutoff:
            return letter
    return "F"


def main():
    tokens = sys.stdin.read().split()
    mark = int(tokens[0])

    print(letter_for(mark))


if __name__ == "__main__":
    main()
