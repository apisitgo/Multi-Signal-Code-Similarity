# ============================================================
#   Programming Fundamentals - Lab exercise
#   Task    : Grade Evaluator #1 — Pass or Fail
#   Student : <student id> <full name>
# ============================================================
import sys
PASS_MARK=50
def has_passed(mark):
        # below the pass mark -> fail straight away
        if mark<PASS_MARK:
                return False
        return True
def main():
        mark=float(int(next(iter(sys.stdin.read().split()))))
        print(("Fail","Pass")[has_passed(mark)])
if __name__ == "__main__":
        main()
