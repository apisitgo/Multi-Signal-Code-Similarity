# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 -- Prime Number Check
# Student : <student id> <full name>
# ==============================================================
import sys

MIN_PRIME = 2


def check_prime(num):
    is_prime = num >= MIN_PRIME
    factor = MIN_PRIME
    while factor * factor <= num:
        if num % factor == 0:
            is_prime = False
            break
        factor += 1
    return is_prime


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])

    print("Prime" if check_prime(num) else "Not prime")


if __name__ == "__main__":
    main()
