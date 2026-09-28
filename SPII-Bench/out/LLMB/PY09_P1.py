# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Print 1..N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    tokens = sys.stdin.read().split()
    limit = int(tokens[0])
    print(" ".join(str(k) for k in range(1, limit + 1)))


if __name__ == "__main__":
    main()
