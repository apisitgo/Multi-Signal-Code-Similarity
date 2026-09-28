nums = input().split()
a = int(nums[0])
b = int(nums[1])

result = 1
count = 0
while count < b:
    result = result * a
    count = count + 1

print(result)
