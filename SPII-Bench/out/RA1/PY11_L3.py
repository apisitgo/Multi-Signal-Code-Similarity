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


def main():
    tokens = sys.stdin.read().split()
    mark = 0
    mark = int(tokens[0])
    letter = ""

    if mark >= A_CUT:
        letter = "A"
    elif mark >= B_CUT:
        letter = "B"
    elif mark >= C_CUT:
        letter = "C"
    elif mark >= D_CUT:
        letter = "D"
    else:
        letter = "F"

    print(letter)


if __name__ == "__main__":
    main()
