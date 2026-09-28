# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 -- Multiplication Table
# Student : <student id> <full name>
# ==============================================================
import sys

LAST_ROW = 12


def print_row(base, row):
    product = base * row
    print(f"{base} x {row} = {product}")


def print_table(base):
    for row in range(1, LAST_ROW + 1):
        print_row(base, row)


def main():
    tokens = sys.stdin.read().split()
    base = 0
    base = int(tokens[0])

    print_table(base)


if __name__ == "__main__":
    main()
