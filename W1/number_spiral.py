tests = int(input())
nums = []

for t in range(tests):
    x, y = list(map(int, input().split(" ")))
    
    value  = max(x, y)
    if value % 2 == 0:
        start_x, start_y = value, 1
    else:
        start_x, start_y = 1, value

    nums.append(str(value ** 2 - abs(x - start_x) - abs(y - start_y)))

print("\n".join(nums))