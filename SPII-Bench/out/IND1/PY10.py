# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #21 — Second Largest in Array
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read n
    n = int(input())

    # Read the array
    numbers = list(map(int, input().split()))

    # Get unique values and sort in descending order
    unique_numbers = list(set(numbers))
    unique_numbers.sort(reverse=True)

    # Second largest is at index 1
    second_largest = unique_numbers[1]

    print(f"Second largest = {second_largest}")


if __name__ == "__main__":
    main()
