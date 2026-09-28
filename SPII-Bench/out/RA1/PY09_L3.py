# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 -- Count to N
# Student : <student id> <full name>
# ==============================================================
import sys

FIRST = 1


def main():
    tokens = sys.stdin.read().split()
    limit = 0
    limit = int(tokens[0])
    line = ""

    for cur in range(FIRST, limit + 1):
        line += str(cur)
        if cur < limit:
            line += " "

    print(line)


if __name__ == "__main__":
    main()
