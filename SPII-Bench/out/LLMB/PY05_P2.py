"""Primality test by trial division up to the square root."""
import sys


def has_divisor(num):
    candidate = 2
    while candidate * candidate <= num:
        if num % candidate == 0:
            return True
        candidate += 1
    return False


def classify(num):
    if num < 2 or has_divisor(num):
        return "Not prime"
    return "Prime"


if __name__ == "__main__":
    value = int(sys.stdin.read().split()[0])
    print(classify(value))
