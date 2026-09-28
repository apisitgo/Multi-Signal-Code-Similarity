import sys

GRADE_TABLE = [
    (80, "A"),
    (70, "B"),
    (60, "C"),
    (50, "D"),
]


def letter_for_score(score_value):
    for cutoff, letter in GRADE_TABLE:
        if score_value >= cutoff:
            return letter
    return "F"


def read_score():
    tokens = sys.stdin.read().split()
    return int(tokens[0])


def main():
    student_score = read_score()
    print(letter_for_score(student_score))


if __name__ == "__main__":
    main()
