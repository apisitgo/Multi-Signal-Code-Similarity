# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

DEPOSIT = "D"
WITHDRAW = "W"

def show_money(x):
    # whole numbers are printed without decimals
    if not math.isinf(x) and x == math.floor(x):
        return str(int(x))
    return f"{x:.2f}"

def main():
    fields = sys.stdin.read().split()
    action = fields[1].upper()   # D = deposit, W = withdraw
    balance = float(fields[0])   # starting balance
    amount = 0.0
    amount = float(fields[2])

    if action == DEPOSIT:
        balance += amount
    elif action == WITHDRAW:
        balance -= amount

    print(f"Balance = {show_money(balance)}")

if __name__ == "__main__":
    main()
