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
    if not math.isinf(amount) and amount == math.floor(amount):
        return str(int(amount))
    return f"{amount:.2f}"

def deposit(balance, amt):
    balance += amt
    print(f"Deposited {money(amt)}, Balance = {money(balance)}")
    return balance

def withdraw(balance, amt):
    balance -= amt
    print(f"Withdrew {money(amt)}, Balance = {money(balance)}")
    return balance

def main():
    balance = 0.0
    tok = sys.stdin.read().split()
    ptr = 0
    # menu: 1 deposit, 2 withdraw, 3 show balance, 4 quit
    while True:
        choice = int(tok[ptr])
        ptr += 1
        if choice == OPT_DEPOSIT:
            balance = deposit(balance, float(tok[ptr]))
            ptr += 1
        elif choice == OPT_WITHDRAW:
            balance = withdraw(balance, float(tok[ptr]))
            ptr += 1
        elif choice == OPT_SHOW:
            print(f"Balance = {money(balance)}")
        elif choice == OPT_QUIT:
            print("Goodbye")
            break

if __name__ == "__main__":
    main()
