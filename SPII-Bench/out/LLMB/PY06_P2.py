"""Prints the 1..12 multiplication table for a given number."""
import sys

TABLE_SIZE = 12


def table_rows(base):
    return [f"{base} x {k} = {base * k}" for k in range(1, TABLE_SIZE + 1)]


def main():
    base = int(sys.stdin.read().split()[0])
    sys.stdout.write("\n".join(table_rows(base)) + "\n")


if __name__ == "__main__":
    main()
