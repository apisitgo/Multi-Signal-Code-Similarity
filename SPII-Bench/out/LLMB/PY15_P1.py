# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Bank Account Menu
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math


def money(value):
    if math.isfinite(value) and value.is_integer():
        return str(int(value))
    return "%.2f" % value


class Account:
    def __init__(self):
        self.balance = 0.0

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited {money(amount)}, Balance = {money(self.balance)}")

    def withdraw(self, amount):
        self.balance -= amount
        print(f"Withdrew {money(amount)}, Balance = {money(self.balance)}")

    def show(self):
        print(f"Balance = {money(self.balance)}")


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    acct = Account()
    while pos < len(tokens):
        choice = int(tokens[pos])
        pos += 1
        if choice == 4:
            print("Goodbye")
            return
        if choice == 3:
            acct.show()
        elif choice in (1, 2):
            amount = float(tokens[pos])
            pos += 1
            if choice == 1:
                acct.deposit(amount)
            else:
                acct.withdraw(amount)


if __name__ == "__main__":
    main()
