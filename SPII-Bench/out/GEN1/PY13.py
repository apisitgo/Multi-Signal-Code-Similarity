# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    scores = [int(input()) for _ in range(n)]
    passed = sum(1 for s in scores if s >= 50)
    failed = n - passed
    avg = sum(scores) / n
    highest = max(scores)
    print(f"Passed = {passed}")
    print(f"Failed = {failed}")
    print(f"Average = {avg:.2f}")
    print(f"Highest = {highest}")
    pass


if __name__ == "__main__":
    main()
