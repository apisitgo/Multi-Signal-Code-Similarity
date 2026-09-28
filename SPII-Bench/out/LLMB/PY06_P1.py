# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Multiplication Table
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def table_lines(base, upto=12):
    return [f"{base} x {k} = {base * k}" for k in range(1, upto + 1)]


def main():
    tokens = sys.stdin.read().split()
    base = int(tokens[0])
    print("\n".join(table_lines(base)))


if __name__ == "__main__":
    main()
