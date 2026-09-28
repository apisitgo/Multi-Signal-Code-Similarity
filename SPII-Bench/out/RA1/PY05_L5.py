# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 -- Prime Number Check
# Student : <student id> <full name>
# ==============================================================
import sys
import itertools

MIN_PRIME = 2


def check_prime(num):
    if num < MIN_PRIME:
        return False
    for factor in itertools.count(MIN_PRIME):
        if factor * factor > num:
            break
        if num % factor == 0:
            return False
    return True


def main():
    tokens = sys.stdin.read().split()
    num = int(tokens[0])

    if check_prime(num):
        verdict = "Prime"
    else:
        verdict = "Not prime"
    print(verdict)


if __name__ == "__main__":
    main()
