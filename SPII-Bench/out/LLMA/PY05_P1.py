import sys


def main():
    n = int(sys.stdin.read().split()[0])
    if n < 2:
        print("Not prime")
        return
    i = 2
    while i * i <= n:
        if n % i == 0:
            print("Not prime")
            return
        i += 1
    print("Prime")


main()
