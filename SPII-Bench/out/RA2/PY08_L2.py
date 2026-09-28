# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
  items = sys.stdin.read().split()
  number = int(items[0])
  text = str(number)
  ndigits = len(text)          # number of digits
  acc = 0

  # add each digit raised to the power ndigits
  for c in text:
    pw = 1
    dig = int(c)
    for k in range(ndigits):
      pw *= dig
    acc += pw

  print("Armstrong" if acc == number else "Not armstrong")


if __name__ == "__main__":
  main()
