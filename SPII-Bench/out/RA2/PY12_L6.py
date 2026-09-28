# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

DEPOSIT = "D"
WITHDRAW = "W"
# sign applied to the amount for each action; unknown actions change nothing
SIGN = {DEPOSIT: 1, WITHDRAW: -1}

def is_whole(x):
    if math.isinf(x):
        return False
    return float(x).is_integer()

def show_money(x):
    # anything with a fraction gets two decimals
    if not is_whole(x):
        return "%.2f" % x
    return str(int(x))

def apply_transaction(balance, action, amount):
    sign = SIGN.get(action)
    if sign is None:
        return balance
    return balance + amount if sign > 0 else balance - amount

def main():
    start, action, amount = sys.stdin.read().split()[:3]
    balance = apply_transaction(float(start), action.upper(), float(amount))
    print("Balance = " + show_money(balance))

if __name__ == "__main__":
    main()
