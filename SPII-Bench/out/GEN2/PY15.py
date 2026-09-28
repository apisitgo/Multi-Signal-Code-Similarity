# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    idx = 0
    balance = 0
    while idx < len(data):
        choice = data[idx]
        idx += 1
        if choice == "1":
            amount = int(data[idx])
            idx += 1
            balance += amount
            print(f"Deposited {amount}, Balance = {balance}")
        elif choice == "2":
            amount = int(data[idx])
            idx += 1
            balance -= amount
            print(f"Withdrew {amount}, Balance = {balance}")
        elif choice == "3":
            print(f"Balance = {balance}")
        elif choice == "4":
            print("Goodbye")
            break
        else:
            print("Invalid choice")


if __name__ == "__main__":
    main()
