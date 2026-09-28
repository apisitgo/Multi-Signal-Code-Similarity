# ------------------------------------------------------------
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #16 — Power (a^b)
#  Student : <student id> <full name>
# ------------------------------------------------------------
import sys
def power(base, times):
    res = 1
    j = 0
    # multiply base by itself 'times' times
    while j < times:
        res = res * base
        j += 1
    return res
def main():
    base, exp = [int(t) for t in sys.stdin.read().split()[:2]]   # base, exponent
    print(power(base, exp))
if __name__ == "__main__":
    main()
