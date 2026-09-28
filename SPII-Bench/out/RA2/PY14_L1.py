# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math


def fmt(v):
    """Print whole values as integers, everything else with 2 decimals."""
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1

    total = 0.0
    max_v = float('-inf')
    min_v = float('inf')

    for i in range(n):
        x = float(data[idx]); idx += 1
        total += x
        if x > max_v: max_v = x
        if x < min_v: min_v = x

    avg = total / n if n > 0 else 0

    print(f"Sum = {fmt(total)}")
    print(f"Average = {fmt(avg)}")
    print(f"Max = {fmt(max_v)}")
    print(f"Min = {fmt(min_v)}")


if __name__ == "__main__":
    main()
