# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 -- One Transaction
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys
import math


def fmt(v):
    # print whole numbers without a decimal point
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    data = sys.stdin.read().split()
    bal = float(data[0])
    op = data[1]
    amt = float(data[2])

    if op.upper() == "D":
        bal += amt
    elif op.upper() == "W":
        bal -= amt

    print(f"Balance = {fmt(bal)}")


if __name__ == "__main__":
    main()
