# class summary program
first_line = input().split()
n = int(first_line[0])

passed = 0
total = 0
highest = -2147483648

count = 0
while count < n:
    line = input()
    x = int(line)
    total = total + x
    if x >= 50:
        passed = passed + 1
    if x > highest:
        highest = x
    count = count + 1

failed = n - passed
print("Passed = " + str(passed))
print("Failed = " + str(failed))

if n > 0:
    avg = total / n
else:
    avg = 0
print("Average = " + format(avg, ".2f"))
print("Highest = " + str(highest))
