# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 — Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def table(n):
    return [f"{n} x {i} = {n * i}" for i in range(1, 13)]


def main():
    n = int(sys.stdin.read().split()[0])
    print("\n".join(table(n)))


if __name__ == "__main__":
    main()
