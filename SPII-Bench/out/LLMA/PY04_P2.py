import sys


def digit_sum(number):
    running_total = 0
    remaining = number
    while remaining > 0:
        last_digit = remaining % 10
        running_total += last_digit
        remaining //= 10
    return running_total


def read_magnitude():
    text_tokens = sys.stdin.read().split()
    return abs(int(text_tokens[0]))


def main():
    magnitude = read_magnitude()
    print(digit_sum(magnitude))


if __name__ == "__main__":
    main()
