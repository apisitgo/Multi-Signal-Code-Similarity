# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    balance = int(input())
    op = input()
    amount = int(input())
    if op == "D":
        balance += amount
    else:
        balance -= amount
    print(f"Balance = {balance}")
    pass


if __name__ == "__main__":
    main()
