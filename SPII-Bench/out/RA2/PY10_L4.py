# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

MIN_LONG = -(2**63)   # smaller than any input value


def read_values():
    buf = sys.stdin.read().split()
    pos = 0
    count = int(buf[pos])
    pos += 1
    values = []
    for j in range(count):
        values.append(int(buf[pos]))
        pos += 1
    return values


def second_largest(values):
    biggest = runner_up = MIN_LONG
    for val in values:
        if val > biggest:
            # old maximum becomes the runner-up
            runner_up = biggest
            biggest = val
        elif val < biggest and val > runner_up:
            runner_up = val
    return runner_up


def main():
    result = second_largest(read_values())
    print(f"Second largest = {result}")


if __name__ == "__main__":
    main()
