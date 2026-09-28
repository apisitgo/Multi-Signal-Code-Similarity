# ============================================================
#   Programming Fundamentals - Lab exercise
#   Task    : Grade Evaluator #1 — Pass or Fail
#   Student : <student id> <full name>
# ============================================================
import sys
PASS_MARK=50
def has_passed(mark):
        # 50 or above is a pass
        return not (mark<PASS_MARK)
def main():
        mark=float(int(next(iter(sys.stdin.read().split()))))
        result="Fail"
        if has_passed(mark):
                result="Pass"
        print(result)
if __name__ == "__main__":
        main()
