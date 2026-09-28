"""Counts from 1 to N on one line."""
import sys


def sequence_line(limit):
    return " ".join(map(str, range(1, limit + 1)))


if __name__ == "__main__":
    limit = int(sys.stdin.read().split()[0])
    print(sequence_line(limit))
