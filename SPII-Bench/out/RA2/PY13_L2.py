# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    tokens = sys.stdin.read().split()
    p = 0
    students = int(tokens[p])
    p += 1

    num_pass = 0
    top = -(2**31)     # like INT_MIN in C
    sum_scores = 0.0

    # go through every score once
    for k in range(students):
        score = int(tokens[p])
        p += 1
        sum_scores += score
        if score >= 50: num_pass += 1
        if score > top: top = score

    print(f"Passed = {num_pass}")
    print(f"Failed = {students - num_pass}")
    mean = sum_scores/students if students > 0 else 0
    print(f"Average = {mean:.2f}")
    print(f"Highest = {top}")


if __name__ == "__main__":
    main()
