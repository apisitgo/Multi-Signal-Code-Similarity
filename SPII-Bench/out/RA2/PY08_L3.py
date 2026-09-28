# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
  acc = 0
  items = sys.stdin.read().split()
  number = int(items[0])
  text = str(number)
  ndigits = len(text)          # number of digits

  # add each digit raised to the power ndigits
  for c in text:
    dig = int(c)
    pw = 1
    for k in range(ndigits):
      pw *= dig
    acc += pw

  is_arm = acc == number
  print("Armstrong" if is_arm else "Not armstrong")


if __name__ == "__main__":
  main()
