import sys


def main():
    base, exp = (int(x) for x in sys.stdin.read().split())
    result = 1
    for _ in range(exp):
        result = result * base
    print(result)


main()
