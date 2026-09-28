import sys


def main():
    n = int(sys.stdin.read().split()[0])
    print(" ".join(str(i) for i in range(1, n + 1)))


main()
