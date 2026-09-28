# print numbers from 1 to n on one line
import sys

def main():
    n = int(sys.stdin.read().split()[0])
    for i in range(1, n + 1):
        if i == n:
            print(i)
        else:
            print(i, end=" ")
    if n < 1:
        print()

if __name__ == "__main__":
    main()
