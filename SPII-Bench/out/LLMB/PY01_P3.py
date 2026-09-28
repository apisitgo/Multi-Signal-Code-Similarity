# Even or Odd checker
# reads a number and tells if it is even or odd

import sys

def main():
    line = sys.stdin.readline()
    x = int(line.strip().split()[0])
    if x % 2 == 0:
        print("Even")
    else:
        print("Odd")

if __name__ == "__main__":
    main()
