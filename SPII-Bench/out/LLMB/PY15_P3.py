# simple bank menu
# 1 = deposit, 2 = withdraw, 3 = balance, 4 = exit
import sys

def fmt(x):
    if x == int(x):
        return str(int(x))
    return "%.2f" % x

def main():
    data = sys.stdin.read().split()
    i = 0
    balance = 0
    while i < len(data):
        choice = int(data[i])
        i += 1
        if choice == 1:
            amount = float(data[i])
            i += 1
            balance = balance + amount
            print("Deposited " + fmt(amount) + ", Balance = " + fmt(balance))
        if choice == 2:
            amount = float(data[i])
            i += 1
            balance = balance - amount
            print("Withdrew " + fmt(amount) + ", Balance = " + fmt(balance))
        if choice == 3:
            print("Balance = " + fmt(balance))
        if choice == 4:
            print("Goodbye")
            break

if __name__ == "__main__":
    main()
