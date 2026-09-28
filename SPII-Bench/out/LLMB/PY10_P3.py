# find the second largest number
import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    nums = []
    for i in range(n):
        nums.append(int(data[i + 1]))
    biggest = max(nums)
    # remove all copies of the biggest, then take max again
    rest = []
    for x in nums:
        if x != biggest:
            rest.append(x)
    if len(rest) == 0:
        second = -(2 ** 63)
    else:
        second = max(rest)
    print("Second largest =", second)

if __name__ == "__main__":
    main()
