# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
A_MIN, B_MIN, C_MIN, D_MIN = 80, 70, 60, 50
def to_letter(points):
    # grade boundaries: 80 / 70 / 60 / 50
    if points >= A_MIN:   return "A"
    elif points >= B_MIN: return "B"
    elif points >= C_MIN: return "C"
    elif points >= D_MIN: return "D"
    return "F"
def main():
    points = float(sys.stdin.read().strip().split()[0])
    sys.stdout.write(to_letter(points) + "\n")
if __name__ == "__main__":
    main()
