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
    if not math.isinf(num) and float(num).is_integer():
        return str(int(num))
    return "%.2f" % num


def collect_stats(values):
    hi, lo = NEG_INF, POS_INF
    acc = 0.0
    k = 0
    while k < len(values):
        val = values[k]
        acc = acc + val
        hi = max(hi, val)
        lo = min(lo, val)
        k += 1
    mean = acc / len(values) if values else 0
    return acc, mean, hi, lo


def main():
    words = sys.stdin.read().split()
    cnt = int(words[0])
    values = [float(w) for w in words[1:1 + cnt]]
    acc, mean, hi, lo = collect_stats(values)
    labels = ("Sum", "Average", "Max", "Min")
    for label, number in zip(labels, (acc, mean, hi, lo)):
        print(label + " = " + pretty(number))


if __name__ == "__main__":
    main()
