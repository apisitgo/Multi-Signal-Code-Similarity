import sys

MIN_SCORE = -(2 ** 31)
PASS_CUTOFF = 50


def summarize_class(score_list):
    pass_count = 0
    top_score = MIN_SCORE
    total_points = 0.0
    for entry in score_list:
        total_points += entry
        if entry >= PASS_CUTOFF:
            pass_count += 1
        if entry > top_score:
            top_score = entry
    return pass_count, total_points, top_score


def parse_scores():
    tokens = sys.stdin.read().split()
    count = int(tokens[0])
    return [int(t) for t in tokens[1:1 + count]], count


def main():
    scores, count = parse_scores()
    pass_count, total_points, top_score = summarize_class(scores)
    average_value = total_points / count if count > 0 else 0
    print(f"Passed = {pass_count}")
    print(f"Failed = {count - pass_count}")
    print(f"Average = {average_value:.2f}")
    print(f"Highest = {top_score}")


if __name__ == "__main__":
    main()
