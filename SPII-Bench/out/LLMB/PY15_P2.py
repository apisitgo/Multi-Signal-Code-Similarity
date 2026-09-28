"""Bank account menu loop driven by numeric commands."""
import sys


def money(x):
    if x in (float("inf"), float("-inf")):
        return "%.2f" % x
    return str(int(x)) if x == int(x) else "%.2f" % x


class Account:
    def __init__(self):
        self.balance = 0.0

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited {money(amount)}, Balance = {money(self.balance)}")

    def withdraw(self, amount):
        self.balance -= amount
        print(f"Withdrew {money(amount)}, Balance = {money(self.balance)}")

    def show(self):
        print(f"Balance = {money(self.balance)}")


def main():
    feed = iter(sys.stdin.read().split())
    acct = Account()
    while True:
        command = int(next(feed))
        if command == 4:
            print("Goodbye")
            return
        if command == 1:
            acct.deposit(float(next(feed)))
        elif command == 2:
            acct.withdraw(float(next(feed)))
        elif command == 3:
            acct.show()


if __name__ == "__main__":
    main()
