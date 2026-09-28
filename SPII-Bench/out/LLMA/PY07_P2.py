import sys


def compute_power(base_value, exponent_value):
    accumulator = 1
    counter = 0
    while counter < exponent_value:
        accumulator *= base_value
        counter += 1
    return accumulator


def parse_inputs():
    tokens = sys.stdin.read().split()
    return int(tokens[0]), int(tokens[1])


def main():
    base_value, exponent_value = parse_inputs()
    print(compute_power(base_value, exponent_value))


if __name__ == "__main__":
    main()
