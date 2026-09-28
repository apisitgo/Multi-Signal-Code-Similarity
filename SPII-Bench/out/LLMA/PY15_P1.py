import sys
import math


def fmt(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def main():
    tokens = sys.stdin.read().split()
    pos = 0
    balance = 0.0
    while True:
        cmd = int(tokens[pos]); pos += 1
        if cmd == 1:
            amt = float(tokens[pos]); pos += 1
            balance += amt
            print(f"Deposited {fmt(amt)}, Balance = {fmt(balance)}")
        elif cmd == 2:
            amt = float(tokens[pos]); pos += 1
            balance -= amt
            print(f"Withdrew {fmt(amt)}, Balance = {fmt(balance)}")
        elif cmd == 3:
            print(f"Balance = {fmt(balance)}")
        elif cmd == 4:
            print("Goodbye")
            break


main()
