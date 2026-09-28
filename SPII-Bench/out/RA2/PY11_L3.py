# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
A_MIN, B_MIN, C_MIN, D_MIN = 80, 70, 60, 50
def main():
    letter = "F"
    raw = sys.stdin.read().split()
    points = float(raw[0])
    # grade boundaries: 80 / 70 / 60 / 50
    if points >= A_MIN:   letter = "A"
    elif points >= B_MIN: letter = "B"
    elif points >= C_MIN: letter = "C"
    elif points >= D_MIN: letter = "D"
    print(letter)
if __name__ == "__main__":
    main()
