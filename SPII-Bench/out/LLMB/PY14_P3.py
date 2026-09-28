# sum, average, max and min of numbers
import sys

def show(name, x):
    # print whole numbers without decimals
    if x == int(x):
        print(name, "=", int(x))
    else:
        print(name, "= %.2f" % x)

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    nums = []
    for i in range(n):
        nums.append(float(data[1 + i]))

    total = 0
    for x in nums:
        total += x
    avg = total / n

    biggest = nums[0]
    smallest = nums[0]
    for x in nums:
        if x > biggest:
            biggest = x
        if x < smallest:
            smallest = x

    show("Sum", total)
    show("Average", avg)
    show("Max", biggest)
    show("Min", smallest)

if __name__ == "__main__":
    main()
