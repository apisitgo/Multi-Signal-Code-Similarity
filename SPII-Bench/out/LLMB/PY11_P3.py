# grade program
import sys

def main():
    score = int(sys.stdin.read().split()[0])
    grade = "F"
    if score >= 50:
        grade = "D"
    if score >= 60:
        grade = "C"
    if score >= 70:
        grade = "B"
    if score >= 80:
        grade = "A"
    print(grade)

if __name__ == "__main__":
    main()
