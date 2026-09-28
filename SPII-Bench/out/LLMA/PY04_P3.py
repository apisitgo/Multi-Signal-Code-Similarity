# add up all the digits of a number
n = int(input())
if n < 0:
    n = -n

total = 0
s = str(n)
for ch in s:
    total = total + int(ch)

print(total)
