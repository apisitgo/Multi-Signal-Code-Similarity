"""Pass/fail decision on a single exam score."""
import sys

PASS_MARK = 50


def verdict(points):
    if points < PASS_MARK:
        return "Fail"
    return "Pass"


def run():
    tokens = sys.stdin.read().split()
    points = int(tokens[0])
    sys.stdout.write(verdict(points) + "\n")


run()
