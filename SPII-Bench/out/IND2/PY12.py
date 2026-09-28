# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    balance = int(data[0])
    op = data[1]
    amount = int(data[2])

    if op == "D":
        balance = balance + amount
    elif op == "W":
        balance = balance - amount

    print("Balance = " + str(balance))


if __name__ == "__main__":
    main()
