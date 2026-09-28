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
    count = int(tokens[0])
    values = list(map(int, tokens[1:1 + count]))
    best, runner_up = LOW, LOW

    k = 0
    while k < count:
        best, runner_up = update_top2(best, runner_up, values[k])
        k += 1

    print(f"Second largest = {runner_up}")


if __name__ == "__main__":
    main()
