import sys
import math


def fmt(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    tokens = sys.stdin.read().split()
    balance = float(tokens[0])
    op = tokens[1].upper()
    amount = float(tokens[2])
    if op == "D":
        balance += amount
    elif op == "W":
        balance -= amount
    print(f"Balance = {fmt(balance)}")


main()
