import sys

PASS_THRESHOLD = 50


def evaluate_result(student_score):
    return "Pass" if student_score >= PASS_THRESHOLD else "Fail"


def fetch_score():
    stream_data = sys.stdin.read().split()
    return int(stream_data[0])


def run():
    score_value = fetch_score()
    verdict = evaluate_result(score_value)
    print(verdict)


if __name__ == "__main__":
    run()
