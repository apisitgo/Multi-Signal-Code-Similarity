# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

PASS_MARK = 50
INT_MIN = -(2**31)     # like INT_MIN in C


def main():
    num_pass, sum_scores, top = 0, 0.0, INT_MIN
    tokens = sys.stdin.read().split()
    p = 0
    students = int(tokens[p])
    p += 1

    # go through every score once
    for k in range(students):
        score = int(tokens[p])
        p += 1
        sum_scores += score
        if score >= PASS_MARK: num_pass += 1
        if score > top: top = score

    num_fail = students - num_pass
    mean = 0
    if students > 0:
        mean = sum_scores/students
    print(f"Passed = {num_pass}")
    print(f"Failed = {num_fail}")
    print(f"Average = {mean:.2f}")
    print(f"Highest = {top}")


if __name__ == "__main__":
    main()
