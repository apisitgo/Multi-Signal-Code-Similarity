# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #1 — One Transaction
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def fmt(x):
    return str(int(x)) if x == int(x) else f"{x:.2f}"


def apply(bal, op, amt):
    op = op.upper()
    if op == "D":
        return bal + amt, None
    if op == "W":
        return bal - amt, None
    return bal, "Invalid operation"


def main():
    d = sys.stdin.read().split()
    bal = float(d[0])
    op = d[1]
    amt = float(d[2])
    bal, err = apply(bal, op, amt)
    if err:
        print(err)
    print(f"Balance = {fmt(bal)}")


if __name__ == "__main__":
    main()
