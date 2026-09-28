# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

POS_INF = float('inf')
NEG_INF = -POS_INF


def pretty(num):
    """Print whole values as integers, everything else with 2 decimals."""
    if not math.isinf(num) and num == math.floor(num):
        return str(int(num))
    return f"{num:.2f}"


def main():
    hi, lo = NEG_INF, POS_INF
    acc = 0.0
    words = sys.stdin.read().split()
    at = 0
    cnt = int(words[at]); at += 1

    for j in range(cnt):
        val = float(words[at]); at += 1
        acc += val
        if val > hi: hi = val
        if val < lo: lo = val

    mean = 0
    if cnt > 0:
        mean = acc / cnt

    print(f"Sum = {pretty(acc)}")
    print(f"Average = {pretty(mean)}")
    print(f"Max = {pretty(hi)}")
    print(f"Min = {pretty(lo)}")


if __name__ == "__main__":
    main()
