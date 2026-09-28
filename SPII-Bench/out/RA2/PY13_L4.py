# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

PASS_MARK = 50
INT_MIN = -(2**31)     # like INT_MIN in C


def read_scores():
    tokens = sys.stdin.read().split()
    p = 0
    students = int(tokens[p])
    p += 1
    scores = []
    for k in range(students):
        scores.append(int(tokens[p]))
        p += 1
    return scores


def summarise(scores):
    num_pass, sum_scores, top = 0, 0.0, INT_MIN
    # go through every score once
    for score in scores:
        sum_scores += score
        if score >= PASS_MARK: num_pass += 1
        if score > top: top = score
    return num_pass, sum_scores, top


def main():
    scores = read_scores()
    students = len(scores)
    num_pass, sum_scores, top = summarise(scores)
    mean = 0
    if students > 0:
        mean = sum_scores/students
    print(f"Passed = {num_pass}")
    print(f"Failed = {students - num_pass}")
    print(f"Average = {mean:.2f}")
    print(f"Highest = {top}")


if __name__ == "__main__":
    main()
