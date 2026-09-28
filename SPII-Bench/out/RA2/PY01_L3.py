#############################################################
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #1 — Even or Odd
#  Student : <student id> <full name>
#############################################################

import sys

DIVISOR = 2

def main():
  # read everything from standard input
  tokens = sys.stdin.read().split()
  num = 0
  num = int( tokens[0] )
  remainder = num % DIVISOR
  # an even number leaves no remainder when divided by 2
  print( "Even" if remainder == 0 else "Odd" )

if __name__ == "__main__":
  main()
