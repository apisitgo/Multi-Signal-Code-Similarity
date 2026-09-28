# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Number Statistics
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math


def pretty(number):
    if math.isfinite(number) and number.is_integer():
        return str(int(number))
    return "%.2f" % number


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    values = [float(t) for t in tokens[1:1 + count]]

    total = sum(values)
    average = total / count if count > 0 else 0
    largest = max(values) if values else float("inf") * -1
    smallest = min(values) if values else float("inf")

    for label, v in (("Sum", total), ("Average", average),
                     ("Max", largest), ("Min", smallest)):
        print(f"{label} = {pretty(v)}")


if __name__ == "__main__":
    main()
