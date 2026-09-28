import sys


def main():
    nums = sys.stdin.read().split()
    x, y = int(nums[0]), int(nums[1])
    while y:
        x, y = y, x % y
    print(x)


main()
