# print multiplication table 1 to 12
num = int(input())
i = 1
while i <= 12:
    ans = num * i
    print(str(num) + " x " + str(i) + " = " + str(ans))
    i = i + 1
