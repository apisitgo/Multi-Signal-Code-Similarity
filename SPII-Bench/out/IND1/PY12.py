# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read initial balance, operation, and amount
    balance = int(input())
    op = input()
    amount = int(input())

    # Apply the transaction
    if op == "D":
        # Deposit
        balance = balance + amount
    elif op == "W":
        # Withdraw
        balance = balance - amount

    print(f"Balance = {balance}")


if __name__ == "__main__":
    main()
