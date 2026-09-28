#############################################################
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #1 — Even or Odd
#  Student : <student id> <full name>
#############################################################

import sys

DIVISOR = 2

def read_number():
  # read everything from standard input
  tokens = sys.stdin.read().split()
  return int( tokens[0] )

def parity_word(num):
  remainder = num % DIVISOR
  # an even number leaves no remainder when divided by 2
  return "Even" if remainder == 0 else "Odd"

def main():
  num = 0
  num = read_number()
  print( parity_word(num) )

if __name__ == "__main__":
  main()
