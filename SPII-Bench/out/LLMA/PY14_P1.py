import sys
import math


def fmt(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    tokens = sys.stdin.read().split()
    n = int(tokens[0])
    vals = [float(x) for x in tokens[1:1 + n]]
    total = sum(vals)
    hi = max(vals) if vals else float('-inf')
    lo = min(vals) if vals else float('inf')
    avg = total / n if n > 0 else 0
    print(f"Sum = {fmt(total)}")
    print(f"Average = {fmt(avg)}")
    print(f"Max = {fmt(hi)}")
    print(f"Min = {fmt(lo)}")


main()
