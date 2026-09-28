# pass or fail program
import sys

def main():
    s = sys.stdin.read().split()
    score = int(s[0])
    if score < 50:
        print("Fail")
    else:
        print("Pass")

if __name__ == "__main__":
    main()
