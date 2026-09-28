# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1

    NEG_INF = -(2**63)   # smaller than any input value
    max_v = NEG_INF
    second = NEG_INF

    for i in range(n):
        x = int(data[idx])
        idx += 1
        if x > max_v:
            # old maximum becomes the runner-up
            second = max_v
            max_v = x
        elif x < max_v and x > second:
            second = x

    print(f"Second largest = {second}")


if __name__ == "__main__":
    main()
