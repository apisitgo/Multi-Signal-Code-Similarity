# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 -- Menu Loop
# Student : <student id> <full name>
# ==============================================================
import sys
import math
import itertools

DEPOSIT = 1
WITHDRAW = 2
CHECK = 3
QUIT = 4


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def do_deposit(it, balance):
    amt = float(next(it))
    balance = balance + amt
    print(f"Deposited {show(amt)}, Balance = {show(balance)}")
    return balance


def do_withdraw(it, balance):
    amt = float(next(it))
    balance = balance - amt
    print(f"Withdrew {show(amt)}, Balance = {show(balance)}")
    return balance


def main():
    it = iter(sys.stdin.read().split())
    balance = 0.0

    for _ in itertools.count():
        choice = int(next(it))
        if choice == DEPOSIT:
            balance = do_deposit(it, balance)
        elif choice == WITHDRAW:
            balance = do_withdraw(it, balance)
        elif choice == CHECK:
            print(f"Balance = {show(balance)}")
        elif choice == QUIT:
            print("Goodbye")
            break


if __name__ == "__main__":
    main()
