# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

OPT_DEPOSIT = 1
OPT_WITHDRAW = 2
OPT_SHOW = 3
OPT_QUIT = 4

def money(amount):
    # drop the decimals when the amount is a whole number
    if not math.isinf(amount) and float(amount).is_integer():
        return str(int(amount))
    return "%.2f" % amount

def deposit(balance, amt):
    balance = balance + amt
    print("Deposited " + money(amt) + ", Balance = " + money(balance))
    return balance

def withdraw(balance, amt):
    balance = balance - amt
    print("Withdrew " + money(amt) + ", Balance = " + money(balance))
    return balance

def main():
    balance = 0.0
    tok = iter(sys.stdin.read().split())
    # menu: 1 deposit, 2 withdraw, 3 show balance, 4 quit
    running = True
    while running:
        choice = int(next(tok))
        if choice == OPT_DEPOSIT:
            balance = deposit(balance, float(next(tok)))
        elif choice == OPT_WITHDRAW:
            balance = withdraw(balance, float(next(tok)))
        elif choice == OPT_SHOW:
            print("Balance = " + money(balance))
        elif choice == OPT_QUIT:
            print("Goodbye")
            running = False

if __name__ == "__main__":
    main()
