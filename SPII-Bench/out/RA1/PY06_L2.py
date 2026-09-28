# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 -- Multiplication Table
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    base = int(tokens[0])

    for row in range(1, 13):
        print(f"{base} x {row} = {base * row}")


if __name__ == "__main__":
    main()
