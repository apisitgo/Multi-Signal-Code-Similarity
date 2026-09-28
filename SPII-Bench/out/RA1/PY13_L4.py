# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 -- Class Summary
# Student : <student id> <full name>
# ==============================================================
import sys

PASS_MARK = 50
LOW = -(2 ** 31)


def parse_scores(tokens):
    pos = 0
    count = int(tokens[pos]); pos += 1
    scores = []
    for k in range(count):
        scores.append(int(tokens[pos])); pos += 1
    return scores


def summarize(scores):
    num_passed = 0
    top_score = LOW
    sum_scores = 0.0
    for score in scores:
        sum_scores += score
        if score >= PASS_MARK:
            num_passed += 1
        if score > top_score:
            top_score = score
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
