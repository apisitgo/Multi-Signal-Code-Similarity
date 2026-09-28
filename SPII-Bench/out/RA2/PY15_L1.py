# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

def fmt(v):
    # drop the decimals when the amount is a whole number
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"

def main():
    data = sys.stdin.read().split()
    idx = 0
    bal = 0.0
    # menu: 1 deposit, 2 withdraw, 3 show balance, 4 quit
    while True:
        c = int(data[idx]); idx += 1
        if c == 1:
            a = float(data[idx]); idx += 1
            bal += a
            print(f"Deposited {fmt(a)}, Balance = {fmt(bal)}")
        elif c == 2:
            a = float(data[idx]); idx += 1
            bal -= a
            print(f"Withdrew {fmt(a)}, Balance = {fmt(bal)}")
        elif c == 3:
            print(f"Balance = {fmt(bal)}")
        elif c == 4:
            print("Goodbye")
            break

if __name__ == "__main__":
    main()
