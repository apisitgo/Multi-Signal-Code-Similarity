# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
A_MIN, B_MIN, C_MIN, D_MIN = 80, 70, 60, 50
# table of (lower bound, letter), checked from the top down
BANDS = [(A_MIN, "A"), (B_MIN, "B"), (C_MIN, "C"), (D_MIN, "D")]
def to_letter(points):
    for low, letter in BANDS:
        if not (points < low):
            return letter
    return "F"
def main():
    points = float(sys.stdin.read().strip().split()[0])
    sys.stdout.write(to_letter(points) + "\n")
if __name__ == "__main__":
    main()
