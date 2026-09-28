# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Grade Evaluator #3 — Class Summary
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys
sys.setrecursionlimit(100000)

PASS_MARK = 50
INT_MIN = -(2**31)     # like INT_MIN in C


def read_scores():
    tokens = sys.stdin.read().split()
    students = int(tokens[0])
    return [int(t) for t in tokens[1:students + 1]]


def summarise(scores, i=0, num_pass=0, sum_scores=0.0, top=INT_MIN):
    # recursive walk over the list, carrying the running results
    if i == len(scores):
        return num_pass, sum_scores, top
    s = scores[i]
    return summarise(scores, i + 1,
                     num_pass + (0 if s < PASS_MARK else 1),
                     sum_scores + s,
                     top if s <= top else s)


def main():
    scores = read_scores()
    students = len(scores)
    num_pass, sum_scores, top = summarise(scores)
    if not students:
        mean = 0
    else:
        mean = sum_scores/students
    out = []
    out.append("Passed = %d" % num_pass)
    out.append("Failed = %d" % (students - num_pass))
    out.append("Average = %.2f" % mean)
    out.append("Highest = %d" % top)
    print("\n".join(out))


if __name__ == "__main__":
    main()
