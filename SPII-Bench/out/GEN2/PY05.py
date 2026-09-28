# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    is_prime = n >= 2
    i = 2
    while i * i <= n and is_prime:
        if n % i == 0:
            is_prime = False
        i += 1
    print("Prime" if is_prime else "Not prime")


if __name__ == "__main__":
    main()
