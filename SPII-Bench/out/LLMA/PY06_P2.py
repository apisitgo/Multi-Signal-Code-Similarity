import sys

TABLE_ROWS = 12


def print_multiplication_row(base, multiplier):
    print(f"{base} x {multiplier} = {base * multiplier}")


def read_base_number():
    tokens = sys.stdin.read().split()
    return int(tokens[0])


def main():
    base_number = read_base_number()
    row = 1
    while row <= TABLE_ROWS:
        print_multiplication_row(base_number, row)
        row += 1


if __name__ == "__main__":
    main()
