# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 -- Count to N
# Student : <student id> <full name>
# ==============================================================
import sys

FIRST = 1


def collect(cur, limit, parts):
    if cur > limit:
        return parts
    parts.append(str(cur))
    return collect(cur + 1, limit, parts)


def build_line(limit):
    parts = collect(FIRST, limit, [])
    return " ".join(parts)


def main():
    tokens = sys.stdin.read().split()
    limit = int(tokens[0])

    print(build_line(limit))


if __name__ == "__main__":
    main()
