# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 -- Armstrong Number
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    s = str(n)
    d = len(s)
    total = 0

    # raise every digit to the power of the digit count
    for ch in s:
        p = 1
        v = int(ch)
        for i in range(d):
            p *= v
        total += p

    print("Armstrong" if total == n else "Not armstrong")


if __name__ == "__main__":
    main()
