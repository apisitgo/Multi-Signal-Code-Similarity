# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SMALLEST_PRIME = 2


def check_prime(value):
	# numbers below 2 are never prime
	if value < SMALLEST_PRIME:
		return False
	# only need to test divisors up to sqrt(value)
	d = SMALLEST_PRIME
	while not (d*d > value):
		if not value%d:
			return False
		d = d + 1
	return True


def main():
	value = int(sys.stdin.read().split()[0])
	if not check_prime(value):
		print("Not prime")
	else:
		print("Prime")


if __name__ == "__main__":
	main()
