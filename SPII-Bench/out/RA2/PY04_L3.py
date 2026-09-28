#------------------------------------------------------------#
# Programming Fundamentals - Lab exercise                    #
# Task    : Algorithm #2 — Sum of Digits                     #
# Student : <student id> <full name>                         #
#------------------------------------------------------------#
import sys

BASE = 10

def main():
   digit_sum = 0
   parts = sys.stdin.read().split()
   raw = int( parts[0] )
   num = abs( raw )   # ignore the sign
   while num > 0:
      last = num % BASE
      digit_sum += last     # last digit
      num //= BASE          # drop last digit
   print( digit_sum )

if __name__ == "__main__":
   main()
