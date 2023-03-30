from collections import defaultdict

def get_cycles(travels, origin, start, cycle, cycles):
    for dest in travels[origin]:
        if dest in cycle:
            cycles.append(cycle + [origin])
        else:
            get_cycles(travels, dest, start, cycle + [origin], cycles)

travels = defaultdict(lambda : set())

n, m = map(int, input().split())

for i in range(m):
    a, b = map(int, input().split())

    travels[a].add(b)

cycle = []
cycles = []

get_cycles(travels, 1, 1, cycle, cycles)

print(cycles)