# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def digit_power(dig, ndigits):
  pw = 1
  for k in range(ndigits):
    pw *= dig
  return pw


def armstrong_sum(text):
  acc = 0
  ndigits = len(text)          # number of digits
  # add each digit raised to the power ndigits
  for c in text:
    acc += digit_power(int(c), ndigits)
  return acc


def main():
  items = sys.stdin.read().split()
  number = int(items[0])
  is_arm = armstrong_sum(str(number)) == number
  print("Armstrong" if is_arm else "Not armstrong")


if __name__ == "__main__":
  main()
