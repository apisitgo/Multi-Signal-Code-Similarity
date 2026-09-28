# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

ROWS = 12

def table_line(base, k):
    product = base * k
    return f"{base} x {k} = {product}"

def print_table(base):
    # print rows 1 .. 12 of the table
    for k in range(1, ROWS + 1):
        print(table_line(base, k))

def main():
    arr = sys.stdin.read().split()
    base = int(arr[0])
    print_table(base)

if __name__ == "__main__":
    main()
