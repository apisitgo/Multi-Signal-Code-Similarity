import sys


def classify_parity(number):
    return "Even" if (number & 1) == 0 else "Odd"


def read_first_int(stream):
    text = stream.read()
    pieces = text.split()
    return int(pieces[0])


def run():
    parsed_number = read_first_int(sys.stdin)
    result_label = classify_parity(parsed_number)
    print(result_label)


if __name__ == "__main__":
    run()
