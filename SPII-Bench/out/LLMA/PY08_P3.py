# check armstrong number
n = int(input())
s = str(n)
d = len(s)
total = 0

for ch in s:
    v = int(ch)
    p = 1
    i = 0
    while i < d:
        p = p * v
        i = i + 1
    total = total + p

if total == n:
    print("Armstrong")
else:
    print("Not armstrong")
