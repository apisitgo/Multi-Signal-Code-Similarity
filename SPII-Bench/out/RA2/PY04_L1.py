#------------------------------------------------------------#
# Programming Fundamentals - Lab exercise                    #
# Task    : Algorithm #2 — Sum of Digits                     #
# Student : <student id> <full name>                         #
#------------------------------------------------------------#
import sys

def main():
   data = sys.stdin.read().split()
   n = abs( int( data[0] ) )   # ignore the sign
   s = 0
   while n > 0:
      s += n % 10     # last digit
      n //= 10        # drop last digit
   print( s )

if __name__ == "__main__":
   main()
