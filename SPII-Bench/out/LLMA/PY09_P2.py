import sys


def build_sequence_text(upper_bound):
    parts = []
    counter = 1
    while counter <= upper_bound:
        parts.append(str(counter))
        counter += 1
    return " ".join(parts)


def main():
    limit_value = int(sys.stdin.read().split()[0])
    output_line = build_sequence_text(limit_value)
    print(output_line)


if __name__ == "__main__":
    main()
