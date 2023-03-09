n = int(input("Inserte un numero : "))
l = []
for i in range(2 ** n):
    l.append(bin(i))
print(l)