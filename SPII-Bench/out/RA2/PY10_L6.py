# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

MIN_LONG = -(2**63)   # smaller than any input value


def read_values():
    buf = sys.stdin.read().split()
    count = int(buf[0])
    return list(map(int, buf[1:1 + count]))


def second_largest(values):
    runner_up = MIN_LONG
    biggest = MIN_LONG
    for val in values:
        # nothing to do for values not above the runner-up
        if val <= runner_up:
            continue
        if val <= biggest:
            if val != biggest:
                runner_up = val
            continue
        # new maximum: old maximum becomes the runner-up
        runner_up, biggest = biggest, val
    return runner_up


def main():
    result = second_largest(read_values())
    print("Second largest = " + str(result))


if __name__ == "__main__":
    main()
