# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 -- Menu Loop
# Student : <student id> <full name>
# ==============================================================
import sys
import math


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    balance = 0.0

    while True:
        choice = int(tokens[pos]); pos += 1
        if choice == 1:
            amt = float(tokens[pos]); pos += 1
            balance += amt
            print(f"Deposited {show(amt)}, Balance = {show(balance)}")
        elif choice == 2:
            amt = float(tokens[pos]); pos += 1
            balance -= amt
            print(f"Withdrew {show(amt)}, Balance = {show(balance)}")
        elif choice == 3:
            print(f"Balance = {show(balance)}")
        elif choice == 4:
            print("Goodbye")
            break


if __name__ == "__main__":
    main()
