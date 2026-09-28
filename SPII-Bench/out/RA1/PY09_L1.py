# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 -- Count to N
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    sb = ""

    # build "1 2 3 ... n"
    for i in range(1, n + 1):
        sb += str(i)
        if i < n:
            sb += " "

    print(sb)


if __name__ == "__main__":
    main()
