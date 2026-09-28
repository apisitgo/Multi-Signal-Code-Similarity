#------------------------------------------------------------#
# Programming Fundamentals - Lab exercise                    #
# Task    : Algorithm #2 — Sum of Digits                     #
# Student : <student id> <full name>                         #
#------------------------------------------------------------#
import sys

BASE = 10

def sum_digits(num):
   digit_sum = 0
   while num > 0:
      last = num % BASE
      digit_sum += last     # last digit
      num //= BASE          # drop last digit
   return digit_sum

def main():
   parts = sys.stdin.read().split()
   raw = int( parts[0] )
   print( sum_digits( abs( raw ) ) )   # ignore the sign

if __name__ == "__main__":
   main()
