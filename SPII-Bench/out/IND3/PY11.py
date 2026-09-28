# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def letter(s):
    if s >= 80:
        return "A"
    if s >= 70:
        return "B"
    if s >= 60:
        return "C"
    if s >= 50:
        return "D"
    return "F"


def main():
    s = int(sys.stdin.read().split()[0])
    print(letter(s))


if __name__ == "__main__":
    main()
