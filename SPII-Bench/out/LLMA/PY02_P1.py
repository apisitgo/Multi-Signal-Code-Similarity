import sys


def main():
    tokens = sys.stdin.read().split()
    mark = int(tokens[0])
    outcome = "Fail"
    if mark >= 50:
        outcome = "Pass"
    print(outcome)


main()
