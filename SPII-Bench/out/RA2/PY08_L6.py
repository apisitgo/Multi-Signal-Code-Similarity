# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def digit_power(dig, ndigits):
  # recursive repeated multiplication
  if ndigits == 0:
    return 1
  return dig * digit_power(dig, ndigits - 1)


def armstrong_sum(text):
  ndigits = len(text)          # number of digits
  # add each digit raised to the power ndigits
  return sum(digit_power(int(c), ndigits) for c in text)


def main():
  number = int(sys.stdin.read().split()[0])
  if number != armstrong_sum(str(number)):
    print("Not armstrong")
    return
  print("Armstrong")


if __name__ == "__main__":
  main()
