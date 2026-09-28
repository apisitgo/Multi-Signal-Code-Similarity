# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

def show_money(x):
    # whole numbers are printed without decimals
    if not math.isinf(x) and x == math.floor(x):
        return str(int(x))
    return f"{x:.2f}"

def main():
    fields = sys.stdin.read().split()
    balance = float(fields[0])   # starting balance
    action  = fields[1]          # D = deposit, W = withdraw
    amount  = float(fields[2])

    if action.upper() == "D":
        balance += amount
    elif action.upper() == "W":
        balance -= amount

    print(f"Balance = {show_money(balance)}")

if __name__ == "__main__":
    main()
