# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 -- Prime Number Check
# Student : <student id> <full name>
# ==============================================================
import sys
import itertools

MIN_PRIME = 2


def has_factor(num):
    for factor in itertools.count(MIN_PRIME):
        if factor * factor > num:
            return False
        if num % factor == 0:
            return True
    return False


def check_prime(num):
    if num < MIN_PRIME:
        return False
    return not has_factor(num)


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])

    verdict = "Not prime"
    if check_prime(num):
        verdict = "Prime"
    print(verdict)


if __name__ == "__main__":
    main()
