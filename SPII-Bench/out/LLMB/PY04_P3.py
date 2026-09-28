# sum of digits
import sys

def main():
    n = int(sys.stdin.read().split()[0])
    text = str(n)
    total = 0
    for ch in text:
        if ch == '-':
            continue
        total = total + int(ch)
    print(total)

if __name__ == "__main__":
    main()
