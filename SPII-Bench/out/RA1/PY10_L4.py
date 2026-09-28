# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 -- Second Largest in Array
# Student : <student id> <full name>
# ==============================================================
import sys

LOW = -(2 ** 63)


def update_top2(best, runner_up, val):
    if val > best:
        return val, best
    if val < best and val > runner_up:
        return best, val
    return best, runner_up


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    count = 0
    count = int(tokens[pos]); pos += 1
    best = LOW
    runner_up = LOW
    val = 0

    for k in range(count):
        val = int(tokens[pos]); pos += 1
        best, runner_up = update_top2(best, runner_up, val)

    print(f"Second largest = {runner_up}")


if __name__ == "__main__":
    main()
