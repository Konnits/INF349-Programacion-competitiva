n = int(input())

nums = list(map(int, input().split(" ")))
cant_towers = 0
towers = []

for num in nums:
    
    inserted = False
    for pos, tower in enumerate(towers):
        if tower[-1] > num:
            towers[pos].append(num)
            inserted = True
            break
        
    if not inserted:
        towers.append([num])
        towers.sort(key = lambda x : x[0], reverse = False)
        cant_towers += 1

print(cant_towers)