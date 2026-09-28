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
    # anything with a fractional part keeps two decimals
    if math.isinf(amount) or not float(amount).is_integer():
        return "%.2f" % amount
    return str(int(amount))

def deposit(balance, tok):
    amt = float(next(tok))
    balance = balance + amt
    print("Deposited " + money(amt) + ", Balance = " + money(balance))
    return balance

def withdraw(balance, tok):
    amt = float(next(tok))
    balance = balance - amt
    print("Withdrew " + money(amt) + ", Balance = " + money(balance))
    return balance

def show(balance, tok):
    print("Balance = " + money(balance))
    return balance

# dispatch table instead of an if/elif chain
ACTIONS = {OPT_DEPOSIT: deposit, OPT_WITHDRAW: withdraw, OPT_SHOW: show}

def main():
    balance = 0.0
    tok = iter(sys.stdin.read().split())
    # menu: 1 deposit, 2 withdraw, 3 show balance, 4 quit
    while True:
        choice = int(next(tok))
        if choice == OPT_QUIT:
            print("Goodbye")
            return
        handler = ACTIONS.get(choice)
        if handler is not None:
            balance = handler(balance, tok)

if __name__ == "__main__":
    main()
