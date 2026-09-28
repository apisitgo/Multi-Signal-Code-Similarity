# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 -- Multiplication Table
# Student : <student id> <full name>
# ==============================================================
import sys

LAST_ROW = 12


def main():
    tokens = sys.stdin.read().split()
    base = 0
    base = int(tokens[0])

    for row in range(1, LAST_ROW + 1):
        product = base * row
        print(f"{base} x {row} = {product}")


if __name__ == "__main__":
    main()
