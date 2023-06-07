def move(p1, p2, p3, value, p_org, p_dest, moves, counter):
    if value == 0:
        return
    elif value == 1:
        [p1, p2, p3][p_org - 1].remove(value)
        [p1, p2, p3][p_dest - 1].append(value)
        moves.append(f"{p_org} {p_dest}")
        counter["move"] += 1
    else:
        pos = [1, 2, 3]
        pos.remove(p_org)
        pos.remove(p_dest)
        new_dest = pos[0]
        move(p1, p2, p3, value - 1, p_org, new_dest, moves, counter)
        [p1, p2, p3][p_org - 1].remove(value)
        [p1, p2, p3][p_dest - 1].append(value)
        moves.append(f"{p_org} {p_dest}")
        counter["move"] += 1
        move(p1, p2, p3, value - 1, new_dest, p_dest, moves, counter)

n = int(input())

p1 = [i for i in range(n , 0, -1)]
p2 = []
p3 = []
moves = []
counter = {"move" : 0}

move(p1, p2, p3, n - 1, 1, 2, moves, counter)
p1.remove(n)
p3.append(n)
moves.append("1 3")
counter["move"] += 1
move(p1, p2, p3, n -1, 2, 3, moves, counter)

print(counter["move"])
print("\n".join(moves))