n = int(input())
s = ""
while n != 1:
    s += str(int(n)) + " "
    if n % 2 == 0:
        n = n / 2
    else:
        n = 3 * n + 1
s += str(int(n))
print(s)