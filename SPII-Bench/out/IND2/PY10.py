# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    numbers = [int(x) for x in data[1:1 + n]]

    # get unique values only
    unique_numbers = []
    for value in numbers:
        if value not in unique_numbers:
            unique_numbers.append(value)

    unique_numbers.sort()
    second_largest = unique_numbers[-2]

    print("Second largest = " + str(second_largest))


if __name__ == "__main__":
    main()
