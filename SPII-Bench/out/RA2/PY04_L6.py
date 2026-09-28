#------------------------------------------------------------#
# Programming Fundamentals - Lab exercise                    #
# Task    : Algorithm #2 — Sum of Digits                     #
# Student : <student id> <full name>                         #
#------------------------------------------------------------#
import sys

BASE = 10

def sum_digits(num):
   # recursion: last digit + sum of the rest
   if num <= 0:
      return 0
   rest, last = divmod( num, BASE )
   return last + sum_digits( rest )

def main():
   raw = int( sys.stdin.read().split()[0] )
   print( sum_digits( -raw if raw < 0 else raw ) )   # ignore the sign

if __name__ == "__main__":
   main()
