import sys


def greatest_common_divisor(first_value, second_value):
    dividend, divisor = first_value, second_value
    while divisor != 0:
        remainder = dividend % divisor
        dividend = divisor
        divisor = remainder
    return dividend


def parse_two_ints(raw_tokens):
    return int(raw_tokens[0]), int(raw_tokens[1])


def run():
    tokens = sys.stdin.read().split()
    num_a, num_b = parse_two_ints(tokens)
    answer = greatest_common_divisor(num_a, num_b)
    print(answer)


if __name__ == "__main__":
    run()
