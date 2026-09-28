# check if number is prime
n = int(input())
is_p = True

if n < 2:
    is_p = False
else:
    i = 2
    while i * i <= n:
        if n % i == 0:
            is_p = False
        i = i + 1

if is_p:
    print("Prime")
else:
    print("Not prime")
