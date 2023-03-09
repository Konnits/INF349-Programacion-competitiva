def increase(l, pos):
    if pos == -1:
        return l
    if l[pos] == "0":
        l[pos] = "1"#amoe esto es para el ramo :/
        return l
    if l[pos] == "1":
        l[pos] = "0"
        return increase(l, pos - 1)

n = int(input("Ingrese un nunero : "))
l = []
aux = ["0"]*n

for i in range(2 ** n):
    l.append("".join(aux))
    aux = increase(aux, n - 1)

print(l)