# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input())
    numbers = [int(input()) for _ in range(n)]
    total = sum(numbers)
    avg = total / n
    print(f"Sum = {total}")
    if avg == int(avg):
        print(f"Average = {int(avg)}")
    else:
        print(f"Average = {avg:.2f}")
    print(f"Max = {max(numbers)}")
    print(f"Min = {min(numbers)}")


if __name__ == "__main__":
    main()
