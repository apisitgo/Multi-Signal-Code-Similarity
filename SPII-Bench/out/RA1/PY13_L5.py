# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 -- Class Summary
# Student : <student id> <full name>
# ==============================================================
import sys

PASS_MARK = 50
LOW = -(2 ** 31)


def parse_scores(tokens):
    count = int(tokens[0])
    return [int(x) for x in tokens[1:1 + count]]


def summarize(scores):
    num_passed = sum(1 for score in scores if score >= PASS_MARK)
    top_score = max(scores) if scores else LOW
    sum_scores = float(sum(scores))
    return num_passed, top_score, sum_scores


def main():
    tokens = sys.stdin.read().split()
    scores = parse_scores(tokens)
    count = len(scores)
    num_passed, top_score, sum_scores = summarize(scores)

    num_failed = count - num_passed
    print(f"Passed = {num_passed}")
    print(f"Failed = {num_failed}")
    mean_score = sum_scores / count if count > 0 else 0
    print(f"Average = {mean_score:.2f}")
    print(f"Highest = {top_score}")


if __name__ == "__main__":
    main()
