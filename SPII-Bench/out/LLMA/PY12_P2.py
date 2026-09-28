import sys
import math


def format_amount(number):
    if math.isinf(number):
        return f"{number:.2f}"
    if number == math.floor(number):
        return str(int(number))
    return f"{number:.2f}"


def apply_transaction(current_balance, action_code, transaction_amount):
    if action_code == "D":
        return current_balance + transaction_amount
    if action_code == "W":
        return current_balance - transaction_amount
    return current_balance


def parse_line(tokens):
    starting_balance = float(tokens[0])
    action_code = tokens[1].upper()
    transaction_amount = float(tokens[2])
    return starting_balance, action_code, transaction_amount


def main():
    tokens = sys.stdin.read().split()
    starting_balance, action_code, transaction_amount = parse_line(tokens)
    final_balance = apply_transaction(starting_balance, action_code, transaction_amount)
    print(f"Balance = {format_amount(final_balance)}")


if __name__ == "__main__":
    main()
