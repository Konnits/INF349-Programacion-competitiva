def safe_increase(l, pos, n):
    if pos == n - 1:
        l[pos] = "1"
        return l
    if pos == 0:
        if l[pos] == "0":
            l[pos] = "1"
        return l
    else:
        if l[pos] == "0":
            l[pos] = "1"
        else:
            l[pos + 1] = "0"
        return l
n = int(input())
pos = n - 1
p = 0

aux = ["0"] * n

for i in range(2 ** n):
    print("".join(aux), pos)
    aux = safe_increase(aux, pos, n)
    if p % 2 == 0:
        pos = pos - 1
        if pos == -1:
            pos = n - 1
            p += 1
    p += 1