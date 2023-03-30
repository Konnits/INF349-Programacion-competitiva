from collections import defaultdict

def make_move(matrix, A_places, n, m, paths = defaultdict(lambda : [])):
    
    new_A_places = []
    have_moves = False
    new_paths = {}

    for i, j in A_places:
        if i + 1 != n  and matrix[i + 1][j] == ".":
            matrix[i + 1][j] = "A"
            new_A_places.append((i + 1, j))
            new_paths[f"{i + 1},{j}"] = paths[f"{i},{j}"] + ["D"]
            have_moves = True
        elif i + 1 != n  and matrix[i + 1][j] == "B":
            return "YES", paths[f"{i},{j}"] + ["D"]
        
        if j + 1 != m and matrix[i][j + 1] == ".":
            matrix[i][j + 1] = "A"
            new_A_places.append((i, j + 1))
            new_paths[f"{i},{j + 1}"] = paths[f"{i},{j}"] + ["R"]
            have_moves = True
        elif j + 1 != m and matrix[i][j + 1] == "B":
            return "YES", paths[f"{i},{j}"] + ["R"]
        
        if j != 0 and matrix[i][j - 1] == ".":
            matrix[i][j - 1] = "A"
            new_A_places.append((i, j - 1))
            new_paths[f"{i},{j - 1}"] = paths[f"{i},{j}"] + ["L"]
            have_moves = True
        elif j != 0 and matrix[i][j - 1] == "B":
            return "YES", paths[f"{i},{j}"] + ["L"]
        
        if i != 0 and matrix[i - 1][j] == ".":
            matrix[i - 1][j] = "A"
            new_A_places.append((i - 1, j))
            new_paths[f"{i - 1},{j}"] = paths[f"{i},{j}"] + ["U"]
            have_moves = True
        elif i != 0 and matrix[i - 1][j] == "B":
            return "YES", paths[f"{i},{j}"] + ["U"]
    if not have_moves:
        return "NO", []
    
    return make_move(matrix, new_A_places, n, m, new_paths)

n, m = map(int, input().split())

matrix = []

for i in range(n):
    row = list(input())
    if "A" in row:
        a_i = i
        a_j = row.index("A")
    matrix.append(row)

value, path = make_move(matrix, [(a_i, a_j)], n, m)
if value == "NO":
    print(value)
else:
    print(value)
    print(len(path))
    print("".join(path))