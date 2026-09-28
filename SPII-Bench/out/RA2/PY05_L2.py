# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
	inp = sys.stdin.read().split()
	value = int(inp[0])

	# numbers below 2 are never prime
	is_prime = value >= 2

	# only need to test divisors up to sqrt(value)
	d = 2
	while d*d <= value:
		if value%d == 0:
			is_prime = False
			break
		d += 1

	print("Prime" if is_prime else "Not prime")


if __name__ == "__main__":
	main()
