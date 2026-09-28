"""Digit sum: adds up the decimal digits of an integer (sign ignored)."""
import sys


def digits_of(text):
    for ch in text:
        if ch.isdigit():
            yield int(ch)


def main():
    raw = sys.stdin.read().split()[0]
    magnitude = str(abs(int(raw)))
    print(sum(digits_of(magnitude)))


if __name__ == "__main__":
    main()
