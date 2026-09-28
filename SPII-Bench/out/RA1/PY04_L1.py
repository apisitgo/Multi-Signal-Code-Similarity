# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #2 -- Sum of Digits
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    data = sys.stdin.read().split()
    n = abs(int(data[0]))  # ignore sign
    s = 0

    # peel off digits from the right and add them up
    while n > 0:
        s += n % 10
        n //= 10

    print(s)


if __name__ == "__main__":
    main()
