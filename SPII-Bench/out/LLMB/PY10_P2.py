"""Finds the second-largest distinct value in a list of integers."""
import sys

FLOOR = -(1 << 63)


def second_largest(values):
    best = FLOOR
    runner = FLOOR
    for v in values:
        if v > best:
            best, runner = v, best
        elif runner < v < best:
            runner = v
    return runner


def main():
    tokens = iter(sys.stdin.read().split())
    count = int(next(tokens))
    numbers = [int(next(tokens)) for _ in range(count)]
    print("Second largest =", second_largest(numbers))


if __name__ == "__main__":
    main()
