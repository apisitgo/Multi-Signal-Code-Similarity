# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a = sys.stdin.read().split()
    b = int(a[0])
    op = a[1]
    n = int(a[2])
    if op == "D":
        b += n
    else:
        b -= n
    print("Balance =", b)


if __name__ == "__main__":
    main()
