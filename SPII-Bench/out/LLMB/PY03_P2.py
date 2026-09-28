"""Greatest common divisor of two integers via recursive Euclid."""
import sys


def euclid(p, q):
    if q == 0:
        return p
    return euclid(q, p % q)


def collect_ints():
    return [int(tok) for tok in sys.stdin.read().split()]


if __name__ == "__main__":
    first, second = collect_ints()[:2]
    print(euclid(first, second))
