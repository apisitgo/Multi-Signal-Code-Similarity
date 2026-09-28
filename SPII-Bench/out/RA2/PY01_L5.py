#############################################################
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #1 — Even or Odd
#  Student : <student id> <full name>
#############################################################

import sys

DIVISOR = 2

def read_number():
  # take the first whitespace separated token
  first = sys.stdin.read().strip().split()[0]
  return int( first )

def parity_word(num):
  remainder = divmod(num, DIVISOR)[1]
  # an even number leaves no remainder when divided by 2
  word = "Odd"
  if remainder == 0:
    word = "Even"
  return word

def main():
  num = read_number()
  sys.stdout.write( parity_word(num) + "\n" )

if __name__ == "__main__":
  main()
