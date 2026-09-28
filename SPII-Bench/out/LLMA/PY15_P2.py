import sys
import math

DEPOSIT, WITHDRAW, SHOW, QUIT = 1, 2, 3, 4


def format_amount(number):
    if math.isinf(number):
        return f"{number:.2f}"
    if number == math.floor(number):
        return str(int(number))
    return f"{number:.2f}"


class TokenReader:
    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0

    def next_int(self):
        val = int(self.tokens[self.pos])
        self.pos += 1
        return val

    def next_float(self):
        val = float(self.tokens[self.pos])
        self.pos += 1
        return val


def main():
    reader = TokenReader(sys.stdin.read().split())
    account_balance = 0.0
    running = True
    while running:
        action = reader.next_int()
        if action == DEPOSIT:
            amount = reader.next_float()
            account_balance += amount
            print(f"Deposited {format_amount(amount)}, Balance = {format_amount(account_balance)}")
        elif action == WITHDRAW:
            amount = reader.next_float()
            account_balance -= amount
            print(f"Withdrew {format_amount(amount)}, Balance = {format_amount(account_balance)}")
        elif action == SHOW:
            print(f"Balance = {format_amount(account_balance)}")
        elif action == QUIT:
            print("Goodbye")
            running = False


if __name__ == "__main__":
    main()
