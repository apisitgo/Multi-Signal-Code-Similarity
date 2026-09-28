"""Maps a numeric score to a letter grade."""
import sys

THRESHOLDS = ((80, "A"), (70, "B"), (60, "C"), (50, "D"))


def letter_for(score):
    for cutoff, letter in THRESHOLDS:
        if score >= cutoff:
            return letter
    return "F"


def main():
    score = int(sys.stdin.read().split()[0])
    print(letter_for(score))


if __name__ == "__main__":
    main()
