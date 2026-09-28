# ============================================================
#   Programming Fundamentals - Lab exercise
#   Task    : Grade Evaluator #1 — Pass or Fail
#   Student : <student id> <full name>
# ============================================================
import sys
PASS_MARK=50
def main():
        words=sys.stdin.read().split()   # all tokens
        mark=float(int(words[0]))
        passed=mark>=PASS_MARK
        # 50 or above is a pass
        print("Pass" if passed else "Fail")
if __name__ == "__main__":
        main()
