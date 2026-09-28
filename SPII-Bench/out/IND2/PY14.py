# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Basic Calculator #3 — Multi-Number Stats
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    numbers = [int(x) for x in data[1:1 + n]]

    total = 0
    highest = numbers[0]
    lowest = numbers[0]

    i = 0
    while i < n:
        value = numbers[i]
        total = total + value
        if value > highest:
            highest = value
        if value < lowest:
            lowest = value
        i = i + 1

    average = total / n

    print("Sum = " + str(total))
    if average == int(average):
        print("Average = " + str(int(average)))
    else:
        print("Average = " + "%.2f" % average)
    print("Max = " + str(highest))
    print("Min = " + str(lowest))


if __name__ == "__main__":
    main()
