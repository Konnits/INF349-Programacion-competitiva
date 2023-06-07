rows, cols = map(int, input().split(" "))

def get_range(r1, c1, r2, c2, prefix_matrix, prefix_horizontal, prefix_vertical):
    r1 -= 1
    c1 -= 1
    r2 -= 1
    c2 -= 1

    sums = prefix_matrix[r2][c2 + 1]

    if r1 - 1 >= 0:
        sums -= prefix_matrix[r1 - 1][c2 + 1]
        sums += prefix_matrix[r1 - 1][c1]
    sums -= prefix_matrix[r2][c1]
        
    
    sums -= prefix_vertical[r1][c2 + 1] - prefix_vertical[r1][c1]
    sums -= prefix_horizontal[r2 + 1][c1] - prefix_horizontal[r1][c1]
    return sums

matrix = []

for i in range(rows):
    matrix.append(input())

queries = int(input())

query_matrix = []

for i in range(queries):
    r1, c1, r2, c2 = map(int, input().split(" "))
    query_matrix.append((r1, c1, r2, c2))

prefix_matrix = [[0] * (cols + 1) for i in range(rows)]
prefix_vertical = [[0] * (cols + 1) for i in range(rows)]
prefix_horizontal = [[0] * cols for i in range(rows + 1)]

for i in range(rows):
    for j in range(cols):
        prev = prefix_matrix[i][j]
        prev_vertical = prefix_vertical[i][j]
        prev_horizontal = prefix_horizontal[i][j]

        if matrix[i][j] == ".":
            if j - 1 >= 0 and matrix[i][j - 1] == ".":
                prev += 1
                prev_horizontal += 1
            if i - 1 >= 0 and matrix[i - 1][j] == ".":
                prev += 1
                prev_vertical += 1

        if i - 1 >= 0:
            if j - 1 >= 0:
                prev -= prefix_matrix[i - 1][j]
            prev += prefix_matrix[i - 1][j + 1]

        prefix_matrix[i][j + 1] = prev
        prefix_vertical[i][j + 1] = prev_vertical
        prefix_horizontal[i + 1][j] = prev_horizontal

for r1, c1, r2, c2 in query_matrix:
    print(get_range(r1, c1, r2, c2, prefix_matrix, prefix_horizontal, prefix_vertical))