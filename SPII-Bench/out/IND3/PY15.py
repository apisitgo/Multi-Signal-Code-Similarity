# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def fmt(x):
    return str(int(x)) if x == int(x) else f"{x:.2f}"


def main():
    d = sys.stdin.read().split()
    i = 0
    bal = 0

    def nxt():
        nonlocal i
        if i >= len(d):
            return None
        t = d[i]
        i += 1
        return t

    while True:
        c = nxt()
        if c is None or c == "4":
            print("Goodbye")
            break
        if c == "1":
            a = float(nxt())
            bal += a
            print(f"Deposited {fmt(a)}, Balance = {fmt(bal)}")
        elif c == "2":
            a = float(nxt())
            bal -= a
            print(f"Withdrew {fmt(a)}, Balance = {fmt(bal)}")
        elif c == "3":
            print(f"Balance = {fmt(bal)}")
        else:
            print("Invalid choice")


if __name__ == "__main__":
    main()
