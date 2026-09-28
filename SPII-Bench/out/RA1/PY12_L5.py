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
    sign = 0
    if action_code == DEPOSIT_CODE:
        sign = 1
    elif action_code == WITHDRAW_CODE:
        sign = -1
    return balance + sign * amount


def main():
    raw = sys.stdin.read().split()
    balance, action, amount_text = raw[0], raw[1], raw[2]
    balance = float(balance)
    amount = float(amount_text)
    action_code = action.upper()

    balance = apply_transaction(balance, action_code, amount)
    print(f"Balance = {show(balance)}")


if __name__ == "__main__":
    main()
