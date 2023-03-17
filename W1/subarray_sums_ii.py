n,value = map(int, input().split())
arr = list(map(int,input().split()))

count=0

prefix_sum = {0: 1}
current_sum = 0
for num in arr:
    current_sum += num
    count += prefix_sum.get(current_sum - value, 0)
    prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1
print(count)