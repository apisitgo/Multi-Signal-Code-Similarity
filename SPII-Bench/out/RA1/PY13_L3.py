# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 -- Class Summary
# Student : <student id> <full name>
# ==============================================================
import sys

PASS_MARK = 50
LOW = -(2 ** 31)


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    count = 0
    count = int(tokens[pos]); pos += 1
    num_passed = 0
    top_score = LOW
    sum_scores = 0.0
    score = 0

    for k in range(count):
        score = int(tokens[pos]); pos += 1
        sum_scores += score
        if score >= PASS_MARK:
            num_passed += 1
        if score > top_score:
            top_score = score

    num_failed = count - num_passed
    print(f"Passed = {num_passed}")
    print(f"Failed = {num_failed}")
    mean_score = sum_scores / count if count > 0 else 0
    print(f"Average = {mean_score:.2f}")
    print(f"Highest = {top_score}")


if __name__ == "__main__":
    main()
