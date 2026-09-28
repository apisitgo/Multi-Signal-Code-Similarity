import sys


def main():
    tokens = sys.stdin.read().split()
    n = int(tokens[0])
    values = [int(v) for v in tokens[1:1 + n]]
    neg_inf = -(2 ** 63)
    best, runner_up = neg_inf, neg_inf
    for v in values:
        if v > best:
            best, runner_up = v, best
        elif best > v > runner_up:
            runner_up = v
    print(f"Second largest = {runner_up}")


main()
