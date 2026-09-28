# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Loops and Patterns #1 — Count to N
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SEP = " "

def build_line(limit):
    parts = []
    num = 1
    # add numbers until we pass the limit
    while True:
        if num > limit:
            break
        parts.append(str(num))
        num += 1
    return SEP.join(parts)

def main():
    limit = int(sys.stdin.read().split()[0])
    print(build_line(limit))

if __name__ == "__main__":
    main()
