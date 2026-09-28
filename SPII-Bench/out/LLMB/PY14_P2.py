"""Sum, average, max and min of a list of real numbers."""
import sys
import math


def show(x):
    if math.isfinite(x) and x == int(x):
        return str(int(x))
    return format(x, ".2f")


def stats(values):
    total = sum(values, 0.0)
    biggest = float("-inf")
    smallest = float("inf")
    for v in values:
        biggest = v if v > biggest else biggest
        smallest = v if v < smallest else smallest
    mean = total / len(values) if values else 0
    return total, mean, biggest, smallest


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    values = [float(t) for t in tokens[1:1 + count]]
    for label, val in zip(("Sum", "Average", "Max", "Min"), stats(values)):
        print(f"{label} = {show(val)}")


if __name__ == "__main__":
    main()
