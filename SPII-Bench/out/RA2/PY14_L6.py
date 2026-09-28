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
    if math.isinf(num) or not float(num).is_integer():
        return "%.2f" % num
    return str(int(num))


def collect_stats(values):
    hi, lo = NEG_INF, POS_INF
    acc = 0.0
    for val in values:
        acc = acc + val
        if val <= hi and val >= lo:
            continue          # neither a new max nor a new min
        if val > hi:
            hi = val
        if val < lo:
            lo = val
    if not values:
        return acc, 0, hi, lo
    return acc, acc / len(values), hi, lo


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
