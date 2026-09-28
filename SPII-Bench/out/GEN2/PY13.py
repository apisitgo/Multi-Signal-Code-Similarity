# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    scores = [int(x) for x in data[1:1 + n]]
    passed = sum(1 for s in scores if s >= 50)
    failed = len(scores) - passed
    average = sum(scores) / len(scores) if scores else 0
    highest = max(scores) if scores else 0
    print(f"Passed = {passed}")
    print(f"Failed = {failed}")
    print(f"Average = {average:.2f}")
    print(f"Highest = {highest}")


if __name__ == "__main__":
    main()
