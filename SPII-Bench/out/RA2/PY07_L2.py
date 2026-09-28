# ------------------------------------------------------------
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #16 — Power (a^b)
#  Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def main():
    nums = sys.stdin.read().split()
    base = int(nums[0])   # base
    exp = int(nums[1])    # exponent
    res = 1
    # multiply base by itself exp times
    for j in range(exp): res *= base
    print(res)
if __name__ == "__main__":
    main()
