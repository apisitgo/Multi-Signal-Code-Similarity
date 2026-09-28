# multi number stats program
first = input().split()
n = int(first[0])

total = 0.0
biggest = -99999999.0
smallest = 99999999.0

i = 0
while i < n:
    line = input()
    x = float(line)
    total = total + x
    if x > biggest:
        biggest = x
    if x < smallest:
        smallest = x
    i = i + 1

if n > 0:
    avg = total / n
else:
    avg = 0


def show(v):
    if v == int(v):
        return str(int(v))
    else:
        return format(v, ".2f")


print("Sum = " + show(total))
print("Average = " + show(avg))
print("Max = " + show(biggest))
print("Min = " + show(smallest))
