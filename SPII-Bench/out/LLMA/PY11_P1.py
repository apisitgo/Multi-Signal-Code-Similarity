import sys


def main():
    s = int(sys.stdin.read().split()[0])
    grade = "F"
    for threshold, letter in ((80, "A"), (70, "B"), (60, "C"), (50, "D")):
        if s >= threshold:
            grade = letter
            break
    print(grade)


main()
