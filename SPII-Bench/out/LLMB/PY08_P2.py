"""Armstrong (narcissistic) number check."""
import sys


def digit_power_sum(text):
    width = len(text)
    acc = 0
    for ch in text:
        acc += int(ch) ** width
    return acc


def main():
    token = sys.stdin.read().split()[0]
    original = int(token)
    label = "Armstrong" if digit_power_sum(str(original)) == original else "Not armstrong"
    print(label)


if __name__ == "__main__":
    main()
