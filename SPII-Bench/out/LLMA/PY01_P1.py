import sys


def main():
    tokens = sys.stdin.read().split()
    value = int(tokens[0])
    remainder = value % 2
    if remainder == 0:
        label = "Even"
    else:
        label = "Odd"
    print(label)


main()
