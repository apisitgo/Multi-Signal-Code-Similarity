# find the second largest number in a list
data = input().split()
n = int(data[0])
nums = input().split()

biggest = -999999999999
second = -999999999999

i = 0
while i < n:
    x = int(nums[i])
    if x > biggest:
        second = biggest
        biggest = x
    else:
        if x < biggest and x > second:
            second = x
    i = i + 1

print("Second largest = " + str(second))
