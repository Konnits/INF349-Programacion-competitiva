n = int(input())
values = []

for i in range(n):
    n, m = list(map(int, input().split(" ")))

    if n > m:
        max_v = n
        min_v = m
    elif n < m:
        max_v = m
        min_v = n
    else:
        if n % 3 == 0:
            values.append("YES")
        else:
            values.append("NO")
        continue
    
    if (max_v - min_v) % 3 == min_v % 3 and min_v * 2 >= max_v:
        values.append("YES")
    else:
        values.append("NO")
print("\n".join(values))