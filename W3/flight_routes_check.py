destinations = set()
origins = set()

n, m = map(int, input().split())

for i in range(m):
    a, b = map(int, input().split())
    origins.add(a)
    destinations.add(b)

if len(destinations - origins) == 0:
    print("YES")
else:
    print("NO")