# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

ROWS = 12

def main():
    arr = sys.stdin.read().split()
    base = int(arr[0])
    product = 0
    # print rows 1 .. 12 of the table
    for k in range(1, ROWS + 1):
        product = base * k
        print(f"{base} x {k} = {product}")

if __name__ == "__main__":
    main()
