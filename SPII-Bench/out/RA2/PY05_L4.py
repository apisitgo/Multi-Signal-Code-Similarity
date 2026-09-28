# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SMALLEST_PRIME = 2


def check_prime(value):
	d = SMALLEST_PRIME
	is_prime = True
	# numbers below 2 are never prime
	if value < SMALLEST_PRIME:
		is_prime = False
	# only need to test divisors up to sqrt(value)
	while d*d <= value:
		if value%d == 0:
			is_prime = False
			break
		d += 1
	return is_prime


def main():
	inp = sys.stdin.read().split()
	value = int(inp[0])
	print("Prime" if check_prime(value) else "Not prime")


if __name__ == "__main__":
	main()
