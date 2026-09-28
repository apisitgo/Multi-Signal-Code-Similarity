# GCD program
# using Euclid method from the lecture
import sys

def main():
    nums = sys.stdin.read().split()
    a = int(nums[0])
    b = int(nums[1])
    # keep going until b is zero
    while True:
        if b == 0:
            break
        remainder = a % b
        a = b
        b = remainder
    print(a)

if __name__ == "__main__":
    main()
