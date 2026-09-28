# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Start with balance 0
    balance = 0

    # Menu loop
    while True:
        # Get choice
        choice = int(input())

        if choice == 1:
            # Deposit
            amount = int(input())
            balance = balance + amount
            print(f"Deposited {amount}, Balance = {balance}")
        elif choice == 2:
            # Withdraw
            amount = int(input())
            balance = balance - amount
            print(f"Withdrew {amount}, Balance = {balance}")
        elif choice == 3:
            # Show balance
            print(f"Balance = {balance}")
        elif choice == 4:
            # Exit
            print("Goodbye")
            break


if __name__ == "__main__":
    main()
