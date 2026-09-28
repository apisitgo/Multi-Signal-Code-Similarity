# count from 1 to n
n = int(input())
result = ""
for i in range(1, n + 1):
    result = result + str(i)
    if i != n:
        result = result + " "
print(result)
