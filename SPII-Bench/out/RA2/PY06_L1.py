# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------

import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    # print rows 1 .. 12 of the table
    for i in range(1,13):
        print(f"{n} x {i} = {n*i}")

if __name__ == "__main__":
    main()
