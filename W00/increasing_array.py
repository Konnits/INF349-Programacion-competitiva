n = int(input())
nums = list(map(int, input().split(" ")))
count = 0

for pos, num in enumerate(nums[1 : ], 1):
    if num < nums[pos - 1]:
        count += nums[pos - 1] - num
        nums[pos] = nums[pos - 1]
print(count)