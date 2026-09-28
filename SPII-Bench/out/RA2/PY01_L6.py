#############################################################
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #1 — Even or Odd
#  Student : <student id> <full name>
#############################################################

import sys

DIVISOR = 2
WORDS = {0: "Even", 1: "Odd"}

def read_number():
  # take the first whitespace separated token
  first = sys.stdin.read().strip().split()[0]
  return int( first )

def parity_word(num):
  remainder = divmod(num, DIVISOR)[1]
  # look the answer up instead of using an if
  return WORDS[remainder]

def main():
  num = read_number()
  sys.stdout.write( parity_word(num) + "\n" )

if __name__ == "__main__":
  main()
