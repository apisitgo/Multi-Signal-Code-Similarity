# ------------------------------------------------------------
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #16 — Power (a^b)
#  Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def power(base, times):
    res = 1
    # multiply base by itself 'times' times
    for j in range(times): res *= base
    return res
def main():
    nums = sys.stdin.read().split()
    base, exp = int(nums[0]), int(nums[1])   # base, exponent
    print(power(base, exp))
if __name__ == "__main__":
    main()
