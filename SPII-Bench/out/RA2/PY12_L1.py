# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

def fmt(v):
    # whole numbers are printed without decimals
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"

def main():
    data = sys.stdin.read().split()
    bal = float(data[0])   # starting balance
    op  = data[1]          # D = deposit, W = withdraw
    amt = float(data[2])

    if op.upper() == "D":
        bal += amt
    elif op.upper() == "W":
        bal -= amt

    print(f"Balance = {fmt(bal)}")

if __name__ == "__main__":
    main()
