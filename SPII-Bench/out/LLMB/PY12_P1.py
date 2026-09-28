# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Bank Balance
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
import math


def money(value):
    if math.isfinite(value) and value.is_integer():
        return str(int(value))
    return "%.2f" % value


def apply(balance, code, amount):
    code = code.upper()
    if code == "D":
        return balance + amount
    if code == "W":
        return balance - amount
    return balance


def main():
    tokens = sys.stdin.read().split()
    balance = apply(float(tokens[0]), tokens[1], float(tokens[2]))
    print("Balance = " + money(balance))


if __name__ == "__main__":
    main()
