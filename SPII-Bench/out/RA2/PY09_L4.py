# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SEP = " "

def build_line(limit):
    line = ""   # output line being built
    last = limit
    for num in range(1, limit+1):
        piece = str(num)
        line += piece
        # separator only between numbers
        if num < last: line += SEP
    return line

def main():
    toks = sys.stdin.read().split()
    print(build_line(int(toks[0])))

if __name__ == "__main__":
    main()
