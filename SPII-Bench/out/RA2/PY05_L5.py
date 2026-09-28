# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys

SMALLEST_PRIME = 2


def check_prime(value):
	is_prime = True
	# numbers below 2 are never prime
	if value < SMALLEST_PRIME:
		is_prime = False
	# only need to test divisors up to sqrt(value)
	for d in range(SMALLEST_PRIME, value + 1):
		if d*d > value:
			break
		if value%d == 0:
			is_prime = False
			break
	return is_prime


def main():
	value = int(sys.stdin.read().split()[0])
	label = "Prime" if check_prime(value) else "Not prime"
	print(label)


if __name__ == "__main__":
	main()
