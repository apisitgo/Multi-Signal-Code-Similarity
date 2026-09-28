# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1

    passed = 0
    max_v = -(2**31)     # like INT_MIN in C
    total = 0.0

    # go through every score once
    for i in range(n):
        x = int(data[idx])
        idx += 1
        total += x
        if x >= 50: passed += 1
        if x > max_v: max_v = x

    print(f"Passed = {passed}")
    print(f"Failed = {n - passed}")
    avg = total/n if n > 0 else 0
    print(f"Average = {avg:.2f}")
    print(f"Highest = {max_v}")


if __name__ == "__main__":
    main()
