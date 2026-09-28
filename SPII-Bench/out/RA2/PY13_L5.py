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
    students = int(tokens[0])
    return [int(t) for t in tokens[1:students + 1]]


def summarise(scores):
    # count passes, add up and keep the best score
    num_pass = sum(1 for s in scores if s >= PASS_MARK)
    sum_scores = float(sum(scores))
    top = max(scores + [INT_MIN])
    return num_pass, sum_scores, top


def main():
    scores = read_scores()
    students = len(scores)
    num_pass, sum_scores, top = summarise(scores)
    mean = sum_scores/students if students else 0
    out = []
    out.append("Passed = %d" % num_pass)
    out.append("Failed = %d" % (students - num_pass))
    out.append("Average = %.2f" % mean)
    out.append("Highest = %d" % top)
    print("\n".join(out))


if __name__ == "__main__":
    main()
