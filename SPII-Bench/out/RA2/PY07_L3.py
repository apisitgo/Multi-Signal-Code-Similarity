# ------------------------------------------------------------
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #16 — Power (a^b)
#  Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def main():
    res = 1
    nums = sys.stdin.read().split()
    base, exp = int(nums[0]), int(nums[1])   # base, exponent
    times = exp
    # multiply base by itself exp times
    for j in range(times): res *= base
    print(res)
if __name__ == "__main__":
    main()
