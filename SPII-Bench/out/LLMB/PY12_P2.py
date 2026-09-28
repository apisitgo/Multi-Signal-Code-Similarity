"""Applies one deposit/withdrawal transaction to a starting balance."""
import sys


def money(x):
    if x != float("inf") and x != float("-inf") and x.is_integer():
        return str(int(x))
    return "%.2f" % x


def apply(balance, kind, amount):
    kind = kind.upper()
    if kind == "D":
        return balance + amount
    if kind == "W":
        return balance - amount
    return balance


def main():
    start, kind, amount = sys.stdin.read().split()[:3]
    result = apply(float(start), kind, float(amount))
    print("Balance = " + money(result))


if __name__ == "__main__":
    main()
