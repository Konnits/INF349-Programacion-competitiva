n = int(input())

arr = []

for i in range(1, n + 1):
    for j in range(1 , n + 1):
        arr.append(i * j)

arr.sort()

pos = n * n // 2

count = 1

while True:
    if count * (count + 1) / 2 >= pos:
        break
    else:
        count += 1
aux = count * (count + 1) / 2

i = count
j = 1

while aux > pos:
    aux -= 1
    i -= 1
    j += 1

print(i * j)
print((n - 1) * 2)
print(arr[n * n // 2])