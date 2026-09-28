# power program (a to the b)
import sys

def main():
    nums = sys.stdin.read().split()
    a = int(nums[0])
    b = int(nums[1])
    print(a ** b)

if __name__ == "__main__":
    main()
