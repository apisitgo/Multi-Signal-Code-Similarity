# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Score Statistics
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

PASS_MARK = 50


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    scores = [int(t) for t in tokens[1:1 + count]]

    passed = sum(1 for s in scores if s >= PASS_MARK)
    highest = max(scores) if scores else -(2 ** 31)
    average = sum(scores) / count if count > 0 else 0

    print(f"Passed = {passed}")
    print(f"Failed = {count - passed}")
    print(f"Average = {average:.2f}")
    print(f"Highest = {highest}")


if __name__ == "__main__":
    main()
