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
    i = 0
    while i < len(values):
        val = values[i]
        if val > biggest:
            # old maximum becomes the runner-up
            runner_up, biggest = biggest, val
        elif runner_up < val < biggest:
            runner_up = val
        i += 1
    return runner_up


def main():
    result = second_largest(read_values())
    print("Second largest = " + str(result))


if __name__ == "__main__":
    main()
