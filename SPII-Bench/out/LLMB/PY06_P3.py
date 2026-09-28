# multiplication table 1 to 12
import sys

def main():
    n = int(sys.stdin.readline().split()[0])
    for i in range(12):
        i = i + 1
        print("%d x %d = %d" % (n, i, n * i))

if __name__ == "__main__":
    main()
