# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

ROWS = 12

def table_line(base, k):
    return "{} x {} = {}".format(base, k, base * k)

def print_table(base, k=1):
    # recursive: print row k, then the remaining rows
    if k > ROWS:
        return
    print(table_line(base, k))
    print_table(base, k + 1)

def main():
    base = int(sys.stdin.read().split()[0])
    print_table(base)

if __name__ == "__main__":
    main()
