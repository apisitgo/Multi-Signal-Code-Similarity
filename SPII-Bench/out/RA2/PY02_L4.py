# ============================================================
#   Programming Fundamentals - Lab exercise
#   Task    : Grade Evaluator #1 — Pass or Fail
#   Student : <student id> <full name>
# ============================================================
import sys
PASS_MARK=50
def has_passed(mark):
        # 50 or above is a pass
        return mark>=PASS_MARK
def main():
        words=sys.stdin.read().split()   # all tokens
        mark=float(int(words[0]))
        print("Pass" if has_passed(mark) else "Fail")
if __name__ == "__main__":
        main()
