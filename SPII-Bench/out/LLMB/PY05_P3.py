# prime number check
import sys

def main():
    n = int(sys.stdin.read().split()[0])
    count = 0
    for i in range(1, n + 1):
        if n % i == 0:
            count += 1
    # a prime has exactly 2 divisors (1 and itself)
    if count == 2:
        print("Prime")
    else:
        print("Not prime")

if __name__ == "__main__":
    main()
