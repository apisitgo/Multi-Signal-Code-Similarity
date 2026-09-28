# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

ROWS = 12

def table_line(base, k):
    return "{} x {} = {}".format(base, k, base * k)

def print_table(base):
    # print rows 1 .. 12 of the table
    k = 1
    while k <= ROWS:
        print(table_line(base, k))
        k = k + 1

def main():
    base = int(sys.stdin.read().split()[0])
    print_table(base)

if __name__ == "__main__":
    main()
