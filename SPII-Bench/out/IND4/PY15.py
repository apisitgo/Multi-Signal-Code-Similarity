# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 — Menu Loop
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    a = sys.stdin.read().split()
    b = 0
    i = 0
    while i < len(a):
        c = a[i]
        i += 1
        if c == "1":
            n = int(a[i])
            i += 1
            b += n
            print("Deposited", str(n) + ",", "Balance =", b)
        elif c == "2":
            n = int(a[i])
            i += 1
            b -= n
            print("Withdrew", str(n) + ",", "Balance =", b)
        elif c == "3":
            print("Balance =", b)
        elif c == "4":
            print("Goodbye")
            break


if __name__ == "__main__":
    main()
