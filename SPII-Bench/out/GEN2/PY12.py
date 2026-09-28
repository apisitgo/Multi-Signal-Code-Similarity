# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    balance = int(data[0])
    op = data[1].upper()
    amount = int(data[2])
    if op == "D":
        balance += amount
    elif op == "W":
        balance -= amount
    else:
        print("Invalid operation")
    print(f"Balance = {balance}")


if __name__ == "__main__":
    main()
