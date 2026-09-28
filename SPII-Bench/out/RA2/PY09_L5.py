# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SEP = " "

def build_line(limit):
    # join all numbers with a single space
    return SEP.join(str(num) for num in range(1, limit+1))

def main():
    limit = int(sys.stdin.read().split()[0])
    print(build_line(limit))

if __name__ == "__main__":
    main()
