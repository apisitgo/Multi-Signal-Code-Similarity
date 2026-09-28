# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 -- Letter Grade
# Student : <student id> <full name>
# ==============================================================
import sys

A_CUT = 80
B_CUT = 70
C_CUT = 60
D_CUT = 50


def letter_for(mark):
    if mark >= A_CUT:
        return "A"
    elif mark >= B_CUT:
        return "B"
    elif mark >= C_CUT:
        return "C"
    elif mark >= D_CUT:
        return "D"
    else:
        return "F"


def main():
    tokens = sys.stdin.read().split()
    mark = 0
    mark = int(tokens[0])

    print(letter_for(mark))


if __name__ == "__main__":
    main()
