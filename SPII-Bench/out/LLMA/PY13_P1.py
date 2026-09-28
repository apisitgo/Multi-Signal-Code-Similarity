import sys


def main():
    tokens = sys.stdin.read().split()
    n = int(tokens[0])
    scores = [int(x) for x in tokens[1:1 + n]]
    passed = sum(1 for x in scores if x >= 50)
    highest = max(scores) if scores else -(2 ** 31)
    avg = sum(scores) / n if n > 0 else 0
    print(f"Passed = {passed}")
    print(f"Failed = {n - passed}")
    print(f"Average = {avg:.2f}")
    print(f"Highest = {highest}")


main()
