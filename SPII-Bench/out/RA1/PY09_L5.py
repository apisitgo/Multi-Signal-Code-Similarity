# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 -- Count to N
# Student : <student id> <full name>
# ==============================================================
import sys

FIRST = 1


def build_line(limit):
    parts = [str(cur) for cur in range(FIRST, limit + 1)]
    return " ".join(parts)


def main():
    tokens = sys.stdin.read().split()
    limit = int(tokens[0])

    print(build_line(limit))


if __name__ == "__main__":
    main()
