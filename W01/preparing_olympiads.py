def sum_groups(nums, groups, l, r, x, prev = []):
    if groups == 1:
        ret = []
        for i in nums:
            harder = max(prev + [i])
            easiest = min(prev + [i])
            v = sum(prev + [i])
            if l <= v and v <= r and harder - easiest >= x:
                ret.append(v)
        return ret
    else:

        ret = []
        for pos, i in enumerate(nums):
            ret += sum_groups(nums[pos + 1 : ], groups - 1, l, r, x, prev + [i])
        return ret

n, l, r, x = list(map(int, input().split(" ")))
nums = list(map(int, input().split(" ")))

cant = 0
ret = []

for i in range(2, n + 1):
    ret += sum_groups(nums, i, l, r, x)
print(len(ret))