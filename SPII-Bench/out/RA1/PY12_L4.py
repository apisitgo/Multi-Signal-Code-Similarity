# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 -- One Transaction
# Student : <student id> <full name>
# ==============================================================
import sys
import math

DEPOSIT_CODE = "D"
WITHDRAW_CODE = "W"


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def apply_transaction(balance, action_code, amount):
    if action_code == DEPOSIT_CODE:
        balance += amount
    elif action_code == WITHDRAW_CODE:
        balance -= amount
    return balance


def main():
    tokens = sys.stdin.read().split()
    balance = 0.0
    balance = float(tokens[0])
    action = tokens[1]
    amount = float(tokens[2])
    action_code = action.upper()

    balance = apply_transaction(balance, action_code, amount)
    print(f"Balance = {show(balance)}")


if __name__ == "__main__":
    main()
