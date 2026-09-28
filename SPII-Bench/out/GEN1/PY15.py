# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    balance = 0
    while True:
        choice = int(input())
        if choice == 1:
            amount = int(input())
            balance += amount
            print(f"Deposited {amount}, Balance = {balance}")
        elif choice == 2:
            amount = int(input())
            balance -= amount
            print(f"Withdrew {amount}, Balance = {balance}")
        elif choice == 3:
            print(f"Balance = {balance}")
        elif choice == 4:
            print("Goodbye")
            break
    pass


if __name__ == "__main__":
    main()
