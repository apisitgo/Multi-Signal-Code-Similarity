# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 -- Multi-Number Stats
# Student : <student id> <full name>
# ==============================================================
import sys
import math


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    count = int(tokens[pos]); pos += 1
    sum_val = 0.0
    hi = float('-inf')
    lo = float('inf')

    for k in range(count):
        num = float(tokens[pos]); pos += 1
        sum_val += num
        if num > hi:
            hi = num
        if num < lo:
            lo = num

    mean_val = sum_val / count if count > 0 else 0
    print(f"Sum = {show(sum_val)}")
    print(f"Average = {show(mean_val)}")
    print(f"Max = {show(hi)}")
    print(f"Min = {show(lo)}")


if __name__ == "__main__":
    main()
