import sys


def is_prime_number(candidate):
    if candidate < 2:
        return False
    divisor = 2
    while divisor * divisor <= candidate:
        if candidate % divisor == 0:
            return False
        divisor += 1
    return True


def main():
    value = int(sys.stdin.read().split()[0])
    verdict = "Prime" if is_prime_number(value) else "Not prime"
    print(verdict)


if __name__ == "__main__":
    main()
