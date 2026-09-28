# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 -- Second Largest in Array
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    count = int(tokens[pos]); pos += 1
    LOW = -(2 ** 63)
    best = LOW
    runner_up = LOW

    for k in range(count):
        val = int(tokens[pos]); pos += 1
        if val > best:
            runner_up = best
            best = val
        elif val < best and val > runner_up:
            runner_up = val

    print(f"Second largest = {runner_up}")


if __name__ == "__main__":
    main()
