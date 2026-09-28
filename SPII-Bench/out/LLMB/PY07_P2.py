"""Integer exponentiation by repeated multiplication."""
import sys
from functools import reduce


def power(base, exponent):
    return reduce(lambda acc, _: acc * base, range(exponent), 1)


def main():
    base, exponent = (int(t) for t in sys.stdin.read().split()[:2])
    print(power(base, exponent))


if __name__ == "__main__":
    main()
