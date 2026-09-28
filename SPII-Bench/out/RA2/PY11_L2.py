# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def main():
    raw = sys.stdin.read().split()
    points = int(raw[0])
    # grade boundaries: 80 / 70 / 60 / 50
    if points >= 80:   letter = "A"
    elif points >= 70: letter = "B"
    elif points >= 60: letter = "C"
    elif points >= 50: letter = "D"
    else:              letter = "F"
    print(letter)
if __name__ == "__main__":
    main()
