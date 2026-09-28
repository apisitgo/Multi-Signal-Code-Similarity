# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    score = int(data[0])
    if score >= 80:
        grade = "A"
    elif score >= 70:
        grade = "B"
    elif score >= 60:
        grade = "C"
    elif score >= 50:
        grade = "D"
    else:
        grade = "F"
    print(grade)


if __name__ == "__main__":
    main()
