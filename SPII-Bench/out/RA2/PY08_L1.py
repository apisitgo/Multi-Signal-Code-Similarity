# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #18 — Armstrong Number
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
  data = sys.stdin.read().split()
  n = int(data[0])
  s = str(n)
  d = len(s)          # number of digits
  total = 0

  # add each digit raised to the power d
  for ch in s:
    p = 1
    v = int(ch)
    for i in range(d):
      p *= v
    total += p

  print("Armstrong" if total == n else "Not armstrong")


if __name__ == "__main__":
  main()
