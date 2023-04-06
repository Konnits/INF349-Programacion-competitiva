n, m = map(int, input().split())
horizontal = list(input())
vertical = list(input())

pos_0_0 = horizontal[0] == ">" or vertical[0] == "v"
pos_0_m = horizontal[0] == "<" or vertical[m - 1] == "v"
pos_n_0 = horizontal[n - 1] == ">" or vertical[0] == "^"
pos_n_m = horizontal[n - 1] == "<" or vertical[m - 1] == "^"

if pos_0_0 and pos_0_m and pos_n_0 and pos_n_m:
    print("YES")
else:
    print("NO")