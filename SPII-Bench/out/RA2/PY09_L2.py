# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

def main():
    toks = sys.stdin.read().split()
    limit = int(toks[0])
    line = ""   # output line being built
    for num in range(1, limit+1):
        line += str(num)
        # separator only between numbers
        if num < limit: line += " "
    print(line)

if __name__ == "__main__":
    main()
