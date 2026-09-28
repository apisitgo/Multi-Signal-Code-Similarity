# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 -- Multi-Number Stats
# Student : <student id> <full name>
# ==============================================================
import sys
import math

NEG_INF = float('-inf')
POS_INF = float('inf')


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def parse_numbers(tokens):
    pos = 0
    count = int(tokens[pos]); pos += 1
    numbers = []
    for k in range(count):
        numbers.append(float(tokens[pos])); pos += 1
    return numbers


def compute_stats(numbers):
    sum_val = 0.0
    hi = NEG_INF
    lo = POS_INF
    for num in numbers:
        sum_val += num
        if num > hi:
            hi = num
        if num < lo:
            lo = num
    return sum_val, hi, lo


def main():
    tokens = sys.stdin.read().split()
    numbers = parse_numbers(tokens)
    count = len(numbers)
    sum_val, hi, lo = compute_stats(numbers)

    mean_val = sum_val / count if count > 0 else 0
    print(f"Sum = {show(sum_val)}")
    print(f"Average = {show(mean_val)}")
    print(f"Max = {show(hi)}")
    print(f"Min = {show(lo)}")


if __name__ == "__main__":
    main()
