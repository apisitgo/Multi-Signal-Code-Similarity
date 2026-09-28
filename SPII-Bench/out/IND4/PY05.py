# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    ok = n >= 2
    i = 2
    while i * i <= n:
        if n % i == 0:
            ok = False
            break
        i += 1
    if ok:
        print("Prime")
    else:
        print("Not prime")


if __name__ == "__main__":
    main()
