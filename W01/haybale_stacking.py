n, k = list(map(int, input().split(" ")))
values = {i : 0 for i in range(n)}
revs = {0 : n}

for instuction in range(k):
    left, right = list(map(int, input().split(" ")))
    
    for i in range(left, right + 1):
        v = values[i]
        revs[v] -= 1
        revs[v + 1] = revs.get(v + 1, 0) + 1
        values[i] += 1

s = 0
for key in revs:
    s += revs[key]
    if s >= n // 2:
        print(key)
        break