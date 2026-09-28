import sys


def digit_power_sum(text_digits, exponent):
    accumulated = 0
    for character in text_digits:
        digit_value = int(character)
        raised = 1
        step = 0
        while step < exponent:
            raised *= digit_value
            step += 1
        accumulated += raised
    return accumulated


def main():
    original_number = int(sys.stdin.read().split()[0])
    digit_text = str(original_number)
    exponent_count = len(digit_text)
    computed_sum = digit_power_sum(digit_text, exponent_count)
    if computed_sum == original_number:
        print("Armstrong")
    else:
        print("Not armstrong")


if __name__ == "__main__":
    main()
