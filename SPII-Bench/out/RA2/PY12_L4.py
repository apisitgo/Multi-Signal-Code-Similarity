# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

DEPOSIT = "D"
WITHDRAW = "W"

def is_whole(x):
    return not math.isinf(x) and x == math.floor(x)

def show_money(x):
    # whole numbers are printed without decimals
    if is_whole(x):
        return str(int(x))
    return f"{x:.2f}"

def apply_transaction(balance, action, amount):
    if action == DEPOSIT:
        balance += amount
    elif action == WITHDRAW:
        balance -= amount
    return balance

def main():
    fields = sys.stdin.read().split()
    action = fields[1].upper()   # D = deposit, W = withdraw
    balance = apply_transaction(float(fields[0]), action, float(fields[2]))
    print(f"Balance = {show_money(balance)}")

if __name__ == "__main__":
    main()
