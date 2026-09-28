# ==============================================================
# Programming Fundamentals - Lab exercise
# Task    : Simple Bank Account #2 -- Menu Loop
# Student : <student id> <full name>
# ==============================================================
import sys
import math

DEPOSIT = 1
WITHDRAW = 2
CHECK = 3
QUIT = 4


def show(v):
    if not math.isinf(v) and v == math.floor(v):
        return str(int(v))
    return f"{v:.2f}"


def do_deposit(it, balance):
    amt = float(next(it))
    balance = balance + amt
    print(f"Deposited {show(amt)}, Balance = {show(balance)}")
    return balance, False


def do_withdraw(it, balance):
    amt = float(next(it))
    balance = balance - amt
    print(f"Withdrew {show(amt)}, Balance = {show(balance)}")
    return balance, False


def do_check(it, balance):
    print(f"Balance = {show(balance)}")
    return balance, False


def do_quit(it, balance):
    print("Goodbye")
    return balance, True


HANDLERS = {
    DEPOSIT: do_deposit,
    WITHDRAW: do_withdraw,
    CHECK: do_check,
    QUIT: do_quit,
}


def run_menu(it, balance):
    choice = int(next(it))
    handler = HANDLERS[choice]
    balance, done = handler(it, balance)
    if done:
        return balance
    return run_menu(it, balance)


def main():
    it = iter(sys.stdin.read().split())
    run_menu(it, 0.0)


if __name__ == "__main__":
    main()
