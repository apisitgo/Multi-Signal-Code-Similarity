# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #16 -- Power (a^b)
# Student : <student id> <full name>
# (reformatted in my own style)
# ==============================================================
import sys


def main():
    data = sys.stdin.read().split()
    a = int(data[0])
    b = int(data[1])
    r = 1

    # multiply a by itself b times
    for i in range(b):
        r *= a

    print(r)


if __name__ == "__main__":
    main()
