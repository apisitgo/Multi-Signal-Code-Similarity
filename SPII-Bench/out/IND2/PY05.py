# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input("Enter an integer: "))

    is_prime = True
    if n < 2:
        is_prime = False
    else:
        i = 2
        while i * i <= n:
            if n % i == 0:
                is_prime = False
                break
            i = i + 1

    if is_prime:
        print("Prime")
    else:
        print("Not prime")


if __name__ == "__main__":
    main()
