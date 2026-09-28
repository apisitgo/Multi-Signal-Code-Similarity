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

    passed = 0
    failed = 0
    total = 0
    highest = scores[0]

    i = 0
    while i < n:
        s = scores[i]
        total = total + s
        if s >= 50:
            passed = passed + 1
        else:
            failed = failed + 1
        if s > highest:
            highest = s
        i = i + 1

    average = total / n

    print("Passed = " + str(passed))
    print("Failed = " + str(failed))
    print("Average = " + "%.2f" % average)
    print("Highest = " + str(highest))


if __name__ == "__main__":
    main()
