# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    unique_sorted = sorted(set(arr), reverse=True)
    print(f"Second largest = {unique_sorted[1]}")
    pass


if __name__ == "__main__":
    main()
