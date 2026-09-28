# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math

def money(amount):
    # drop the decimals when the amount is a whole number
    if not math.isinf(amount) and amount == math.floor(amount):
        return str(int(amount))
    return f"{amount:.2f}"

def main():
    tok = sys.stdin.read().split()
    ptr = 0
    balance = 0.0
    # menu: 1 deposit, 2 withdraw, 3 show balance, 4 quit
    while True:
        choice = int(tok[ptr]); ptr += 1
        if choice == 1:
            amt = float(tok[ptr]); ptr += 1
            balance += amt
            print(f"Deposited {money(amt)}, Balance = {money(balance)}")
        elif choice == 2:
            amt = float(tok[ptr]); ptr += 1
            balance -= amt
            print(f"Withdrew {money(amt)}, Balance = {money(balance)}")
        elif choice == 3:
            print(f"Balance = {money(balance)}")
        elif choice == 4:
            print("Goodbye")
            break

if __name__ == "__main__":
    main()
