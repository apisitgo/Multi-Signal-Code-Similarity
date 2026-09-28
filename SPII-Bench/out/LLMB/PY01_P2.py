"""Parity classifier: reads one integer and reports whether it is even or odd."""
from sys import stdin

LABELS = {0: "Even", 1: "Odd"}


def parity_of(value):
    return value & 1


def read_first_token():
    for token in stdin.read().split():
        return token
    return "0"


if __name__ == "__main__":
    number = int(read_first_token())
    print(LABELS[parity_of(number)])
