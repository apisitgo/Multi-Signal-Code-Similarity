score = int(input())

grade = ""
if score >= 80:
    grade = "A"
if score >= 70 and score < 80:
    grade = "B"
if score >= 60 and score < 70:
    grade = "C"
if score >= 50 and score < 60:
    grade = "D"
if score < 50:
    grade = "F"

print(grade)
