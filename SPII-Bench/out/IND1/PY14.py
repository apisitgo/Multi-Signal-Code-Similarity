# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read n
    n = int(input())

    # Read all numbers
    numbers = []
    for i in range(n):
        num = int(input())
        numbers.append(num)

    # Calculate statistics
    total = sum(numbers)
    average = total / n
    max_num = max(numbers)
    min_num = min(numbers)

    # Print results
    print(f"Sum = {total}")
    print(f"Average = {average:.2f}")
    print(f"Max = {max_num}")
    print(f"Min = {min_num}")


if __name__ == "__main__":
    main()
