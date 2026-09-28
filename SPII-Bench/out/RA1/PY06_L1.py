# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #2 -- Multiplication Table
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])

    # print rows 1 through 12
    for i in range(1, 13):
        print(f"{n} x {i} = {n * i}")


if __name__ == "__main__":
    main()
