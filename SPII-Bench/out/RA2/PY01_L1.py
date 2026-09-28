#############################################################
#  Programming Fundamentals - Lab exercise
#  Task    : Algorithm #1 — Even or Odd
#  Student : <student id> <full name>
#############################################################

import sys

def main():
  # read everything from standard input
  data = sys.stdin.read().split()
  n = int( data[0] )
  # an even number leaves no remainder when divided by 2
  print( "Even" if n%2 == 0 else "Odd" )

if __name__ == "__main__":
  main()
