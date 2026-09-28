# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    if n < 2:
        print("Not prime")
    else:
        is_prime = True
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                is_prime = False
                break
        print("Prime" if is_prime else "Not prime")
    pass


if __name__ == "__main__":
    main()
