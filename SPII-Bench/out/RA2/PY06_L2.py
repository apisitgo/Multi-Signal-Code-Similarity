# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

def main():
    arr = sys.stdin.read().split()
    base = int(arr[0])
    # print rows 1 .. 12 of the table
    for k in range(1,13):
        print(f"{base} x {k} = {base*k}")

if __name__ == "__main__":
    main()
