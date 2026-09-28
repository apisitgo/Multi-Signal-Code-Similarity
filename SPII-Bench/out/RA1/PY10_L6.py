# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 -- Second Largest in Array
# Student : <student id> <full name>
# ==============================================================
import sys

LOW = -(2 ** 63)


def update_top2(best, runner_up, val):
    if val <= best:
        if val > runner_up and val < best:
            return best, val
        return best, runner_up
    return val, best


def scan(values, k, best, runner_up):
    if k >= len(values):
        return best, runner_up
    best, runner_up = update_top2(best, runner_up, values[k])
    return scan(values, k + 1, best, runner_up)


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    values = list(map(int, tokens[1:1 + count]))

    _, runner_up = scan(values, 0, LOW, LOW)
    print(f"Second largest = {runner_up}")


if __name__ == "__main__":
    main()
