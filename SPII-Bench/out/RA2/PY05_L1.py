# ------------------------------------------------------------
# Programming Fundamentals - Lab exercise
# Task    : Algorithm #5 — Prime Number Check
# Student : <student id> <full name>
# ------------------------------------------------------------
import sys


def main():
	data = sys.stdin.read().split()
	n = int(data[0])

	# numbers below 2 are never prime
	prime = n >= 2

	# only need to test divisors up to sqrt(n)
	i = 2
	while i*i <= n:
		if n%i == 0:
			prime = False
			break
		i += 1

	print("Prime" if prime else "Not prime")


if __name__ == "__main__":
	main()
