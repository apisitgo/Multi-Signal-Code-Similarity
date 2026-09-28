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
      num, last = divmod( num, BASE )   # split off last digit
      digit_sum = digit_sum + last
   return digit_sum

def main():
   raw = int( sys.stdin.read().strip().split()[0] )
   print( sum_digits( abs( raw ) ) )   # ignore the sign

if __name__ == "__main__":
   main()
