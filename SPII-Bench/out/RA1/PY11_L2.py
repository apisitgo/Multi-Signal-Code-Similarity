# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 -- Letter Grade
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    mark = int(tokens[0])

    if mark >= 80:
        letter = "A"
    elif mark >= 70:
        letter = "B"
    elif mark >= 60:
        letter = "C"
    elif mark >= 50:
        letter = "D"
    else:
        letter = "F"

    print(letter)


if __name__ == "__main__":
    main()
