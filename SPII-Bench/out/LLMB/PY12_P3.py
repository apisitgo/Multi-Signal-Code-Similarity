# bank deposit / withdraw
import sys

def print_money(x):
    if x == int(x):
        print("Balance =", int(x))
    else:
        print("Balance = %.2f" % x)

def main():
    data = sys.stdin.read().split()
    balance = float(data[0])
    kind = data[1]
    amount = float(data[2])
    if kind == "D" or kind == "d":
        balance = balance + amount
    elif kind == "W" or kind == "w":
        balance = balance - amount
    print_money(balance)

if __name__ == "__main__":
    main()
