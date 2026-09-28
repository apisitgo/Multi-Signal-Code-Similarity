# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 -- Menu Loop
# Student : <student id> <full name>
# ==============================================================
import sys
import math

DEPOSIT = 1
WITHDRAW = 2
CHECK = 3
QUIT = 4


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def do_deposit(tokens, pos, balance):
    amt = float(tokens[pos]); pos += 1
    balance += amt
    print(f"Deposited {show(amt)}, Balance = {show(balance)}")
    return pos, balance


def do_withdraw(tokens, pos, balance):
    amt = float(tokens[pos]); pos += 1
    balance -= amt
    print(f"Withdrew {show(amt)}, Balance = {show(balance)}")
    return pos, balance


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    balance = 0.0
    choice = 0

    while True:
        choice = int(tokens[pos]); pos += 1
        if choice == DEPOSIT:
            pos, balance = do_deposit(tokens, pos, balance)
        elif choice == WITHDRAW:
            pos, balance = do_withdraw(tokens, pos, balance)
        elif choice == CHECK:
            print(f"Balance = {show(balance)}")
        elif choice == QUIT:
            print("Goodbye")
            break


if __name__ == "__main__":
    main()
