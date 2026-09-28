"""Class summary: pass/fail counts, average and highest score."""
import sys

PASS_MARK = 50


def summarize(scores):
    passed = sum(1 for s in scores if s >= PASS_MARK)
    highest = max(scores) if scores else -(2 ** 31)
    average = (sum(scores) / len(scores)) if scores else 0
    return passed, len(scores) - passed, average, highest


def main():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    scores = [int(t) for t in tokens[1:1 + count]]
    passed, failed, average, highest = summarize(scores)
    print("Passed =", passed)
    print("Failed =", failed)
    print("Average = %.2f" % average)
    print("Highest =", highest)


if __name__ == "__main__":
    main()
