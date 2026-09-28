# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Second Largest
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def second_largest(values):
    floor = -(2 ** 63)
    best = floor
    runner_up = floor
    for v in values:
        if v > best:
            runner_up, best = best, v
        elif best > v > runner_up:
            runner_up = v
    return runner_up


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    values = [int(t) for t in tokens[1:1 + count]]
    print(f"Second largest = {second_largest(values)}")


if __name__ == "__main__":
    main()
