#------------------------------------------------------------#
# Programming Fundamentals - Lab exercise                    #
# Task    : Algorithm #2 — Sum of Digits                     #
# Student : <student id> <full name>                         #
#------------------------------------------------------------#
import sys

def main():
   parts = sys.stdin.read().split()
   num = abs( int( parts[0] ) )   # ignore the sign
   digit_sum = 0
   while num > 0:
      digit_sum += num % 10     # last digit
      num //= 10                # drop last digit
   print( digit_sum )

if __name__ == "__main__":
   main()
