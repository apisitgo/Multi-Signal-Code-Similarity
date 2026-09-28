# find gcd of two numbers
data = input().split()
a = int(data[0])
b = int(data[1])

while True:
    if b == 0:
        break
    r = a % b
    a = b
    b = r

print(a)
