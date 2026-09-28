# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    nums = [int(x) for x in data[1:1 + n]]
    largest = None
    second = None
    for x in nums:
        if largest is None or x > largest:
            if largest is not None:
                second = largest
            largest = x
        elif x < largest and (second is None or x > second):
            second = x
    if second is None:
        print("No second largest")
    else:
        print(f"Second largest = {second}")


if __name__ == "__main__":
    main()
