import sys


def main():
    n = int(sys.stdin.read().split()[0])
    lines = [f"{n} x {i} = {n * i}" for i in range(1, 13)]
    print("\n".join(lines))


main()
