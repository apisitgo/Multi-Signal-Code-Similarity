# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    n = int(input("Enter an integer: "))

    # count how many digits n has
    num_digits = len(str(n))

    total = 0
    temp = n
    while temp > 0:
        digit = temp % 10
        total = total + digit ** num_digits
        temp = temp // 10

    if total == n:
        print("Armstrong Number")
    else:
        print("Not Armstrong Number")


if __name__ == "__main__":
    main()
