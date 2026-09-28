# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    index = 0
    balance = 0

    running = True
    while running:
        choice = data[index]
        index = index + 1

        if choice == "1":
            amount = int(data[index])
            index = index + 1
            balance = balance + amount
            print("Deposited " + str(amount) + ", Balance = " + str(balance))
        elif choice == "2":
            amount = int(data[index])
            index = index + 1
            balance = balance - amount
            print("Withdrew " + str(amount) + ", Balance = " + str(balance))
        elif choice == "3":
            print("Balance = " + str(balance))
        elif choice == "4":
            print("Goodbye")
            running = False


if __name__ == "__main__":
    main()
