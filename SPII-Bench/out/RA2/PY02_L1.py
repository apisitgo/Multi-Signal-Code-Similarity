# ============================================================
#   Programming Fundamentals - Lab exercise
#   Task    : Grade Evaluator #1 — Pass or Fail
#   Student : <student id> <full name>
# ============================================================
import sys
def main():
        data=sys.stdin.read().split()   # all tokens
        score=int(data[0])
        # 50 or above is a pass
        print("Pass" if score>=50 else "Fail")
if __name__ == "__main__":
        main()
