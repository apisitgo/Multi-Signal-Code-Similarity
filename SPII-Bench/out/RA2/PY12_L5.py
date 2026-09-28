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
    return (not math.isinf(x)) and float(x).is_integer()

def show_money(x):
    # whole numbers are printed without decimals
    if is_whole(x):
        return str(int(x))
    return "%.2f" % x

def apply_transaction(balance, action, amount):
    if action == DEPOSIT:
        balance = balance + amount
    elif action == WITHDRAW:
        balance = balance - amount
    return balance

def main():
    start, action, amount = sys.stdin.read().split()[:3]
    balance = apply_transaction(float(start), action.upper(), float(amount))
    print("Balance = " + show_money(balance))

if __name__ == "__main__":
    main()
