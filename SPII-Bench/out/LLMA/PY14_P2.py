import sys
import math


def format_number(number):
    if math.isinf(number):
        return f"{number:.2f}"
    if number == math.floor(number):
        return str(int(number))
    return f"{number:.2f}"


def compute_stats(values):
    running_total = 0.0
    running_max = float('-inf')
    running_min = float('inf')
    for entry in values:
        running_total += entry
        if entry > running_max:
            running_max = entry
        if entry < running_min:
            running_min = entry
    return running_total, running_max, running_min


def parse_values():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    return [float(t) for t in tokens[1:1 + count]], count


def main():
    values, count = parse_values()
    total, hi, lo = compute_stats(values)
    average = total / count if count > 0 else 0
    print(f"Sum = {format_number(total)}")
    print(f"Average = {format_number(average)}")
    print(f"Max = {format_number(hi)}")
    print(f"Min = {format_number(lo)}")


if __name__ == "__main__":
    main()
