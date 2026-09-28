import sys

VERY_SMALL = -(2 ** 63)


def find_second_largest(sequence):
    top_value = VERY_SMALL
    runner_up_value = VERY_SMALL
    for element in sequence:
        if element > top_value:
            runner_up_value = top_value
            top_value = element
        elif element < top_value and element > runner_up_value:
            runner_up_value = element
    return runner_up_value


def parse_sequence():
    words = sys.stdin.read().split()
    count = int(words[0])
    return [int(w) for w in words[1:1 + count]]


def main():
    items = parse_sequence()
    answer = find_second_largest(items)
    print(f"Second largest = {answer}")


if __name__ == "__main__":
    main()
