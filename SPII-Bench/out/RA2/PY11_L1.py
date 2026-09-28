# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #2 — Letter Grade
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def main():
    data = sys.stdin.read().split()
    s = int(data[0])
    # grade boundaries: 80 / 70 / 60 / 50
    if s >= 80:   g = "A"
    elif s >= 70: g = "B"
    elif s >= 60: g = "C"
    elif s >= 50: g = "D"
    else:         g = "F"
    print(g)
if __name__ == "__main__":
    main()
