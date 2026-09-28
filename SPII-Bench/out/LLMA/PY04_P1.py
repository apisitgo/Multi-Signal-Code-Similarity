import sys


def main():
    n = abs(int(sys.stdin.read().split()[0]))
    total = 0
    while n != 0:
        total, n = total + n % 10, n // 10
    print(total)


main()
