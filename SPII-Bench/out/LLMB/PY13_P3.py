# class score report
import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    scores = []
    for i in range(1, n + 1):
        scores.append(int(data[i]))

    passed = 0
    failed = 0
    for s in scores:
        if s >= 50:
            passed = passed + 1
        else:
            failed = failed + 1

    total = 0
    for s in scores:
        total = total + s

    highest = scores[0]
    for s in scores:
        if s > highest:
            highest = s

    print("Passed =", passed)
    print("Failed =", failed)
    print("Average = %.2f" % (total / n))
    print("Highest =", highest)

if __name__ == "__main__":
    main()
