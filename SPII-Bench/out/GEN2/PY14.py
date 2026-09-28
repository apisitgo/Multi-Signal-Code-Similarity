# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    nums = []
    for x in data[1:1 + n]:
        v = float(x)
        nums.append(int(v) if v.is_integer() else v)

    def fmt(v):
        if float(v).is_integer():
            return str(int(v))
        return f"{v:.2f}"

    total = sum(nums)
    average = total / n if n > 0 else 0
    print(f"Sum = {fmt(total)}")
    print(f"Average = {fmt(average)}")
    print(f"Max = {fmt(max(nums))}")
    print(f"Min = {fmt(min(nums))}")


if __name__ == "__main__":
    main()
