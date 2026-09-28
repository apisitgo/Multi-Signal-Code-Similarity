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


def print_table(base, row=1):
    if row > LAST_ROW:
        return
    print_row(base, row)
    print_table(base, row + 1)


def main():
    tokens = sys.stdin.read().split()
    base = int(tokens[0])

    print_table(base)


if __name__ == "__main__":
    main()
