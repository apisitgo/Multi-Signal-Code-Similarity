# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 -- Prime Number Check
# Student : <student id> <full name>
# ==============================================================
import sys


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])
    is_prime = num >= 2

    factor = 2
    while factor * factor <= num:
        if num % factor == 0:
            is_prime = False
            break
        factor += 1

    print("Prime" if is_prime else "Not prime")


if __name__ == "__main__":
    main()
