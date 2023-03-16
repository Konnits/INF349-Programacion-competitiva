n = int(input())
nums = input().split(" ")
nums.sort(key = lambda x : int(x))

if str(n) not in nums:
    print(n)
else:
    for pos, i in enumerate(nums):
        if str(pos + 1) != i:
            print(pos + 1)
            break