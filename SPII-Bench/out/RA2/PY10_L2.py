# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    buf = sys.stdin.read().split()
    pos = 0
    count = int(buf[pos])
    pos += 1

    MIN_LONG = -(2**63)   # smaller than any input value
    biggest = MIN_LONG
    runner_up = MIN_LONG

    for j in range(count):
        val = int(buf[pos])
        pos += 1
        if val > biggest:
            # old maximum becomes the runner-up
            runner_up = biggest
            biggest = val
        elif val < biggest and val > runner_up:
            runner_up = val

    print(f"Second largest = {runner_up}")


if __name__ == "__main__":
    main()
