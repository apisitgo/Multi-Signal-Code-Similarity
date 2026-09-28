# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SEP = " "

def main():
    toks = sys.stdin.read().split()
    line = ""   # output line being built
    limit = int(toks[0])
    last = limit
    for num in range(1, limit+1):
        piece = str(num)
        line += piece
        # separator only between numbers
        if num < last: line += SEP
    print(line)

if __name__ == "__main__":
    main()
