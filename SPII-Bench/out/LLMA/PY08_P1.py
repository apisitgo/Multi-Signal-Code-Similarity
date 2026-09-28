import sys


def main():
    n = int(sys.stdin.read().split()[0])
    digits = str(n)
    power = len(digits)
    total = sum(int(ch) ** power for ch in digits)
    print("Armstrong" if total == n else "Not armstrong")


main()
