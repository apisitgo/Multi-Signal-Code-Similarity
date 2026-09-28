# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
    # Read number of students
    n = int(input())

    # Read all grades
    grades = []
    for i in range(n):
        grade = int(input())
        grades.append(grade)

    # Count passed and failed
    passed = 0
    failed = 0
    total = 0
    max_grade = grades[0]

    for grade in grades:
        if grade >= 50:
            passed = passed + 1
        else:
            failed = failed + 1

        total = total + grade

        if grade > max_grade:
            max_grade = grade

    # Calculate average with 2 decimal places
    average = total / n

    # Print results
    print(f"Passed = {passed}")
    print(f"Failed = {failed}")
    print(f"Average = {average:.2f}")
    print(f"Highest = {max_grade}")


if __name__ == "__main__":
    main()
