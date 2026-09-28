# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def digit_power(dig, ndigits):
  pw = 1
  k = 0
  while k < ndigits:
    pw = pw * dig
    k = k + 1
  return pw


def armstrong_sum(text):
  ndigits = len(text)          # number of digits
  # add each digit raised to the power ndigits
  return sum(digit_power(int(c), ndigits) for c in text)


def main():
  number = int(sys.stdin.read().split()[0])
  is_arm = number == armstrong_sum(str(number))
  print("Armstrong" if is_arm else "Not armstrong")


if __name__ == "__main__":
  main()
