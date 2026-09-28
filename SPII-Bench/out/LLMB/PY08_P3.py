# Armstrong number check
# e.g. 153 = 1^3 + 5^3 + 3^3
import sys

def main():
    n = int(sys.stdin.read().split()[0])
    # count digits
    digits = 0
    temp = n
    while temp > 0:
        digits += 1
        temp = temp // 10
    # sum of each digit to the power of digits
    total = 0
    temp = n
    while temp > 0:
        d = temp % 10
        total += d ** digits
        temp = temp // 10
    if total == n:
        print("Armstrong")
    else:
        print("Not armstrong")

if __name__ == "__main__":
    main()
