# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def is_prime(value):
    if value < 2:
        return False
    divisor = 2
    while divisor * divisor <= value:
        if value % divisor == 0:
            return False
        divisor += 1
    return True


def main():
    tokens = sys.stdin.read().split()
    value = int(tokens[0])
    print("Prime" if is_prime(value) else "Not prime")


if __name__ == "__main__":
    main()
