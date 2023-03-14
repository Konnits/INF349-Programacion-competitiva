n = int(input())
nums = list(range(1, n + 1))

if n == 2 or n == 3:
    print("NO SOLUTION")
else:
    if n == 1:
        print("1")
    else:
        odd = False
        if n % 2 == 0:
            div = n // 2
        else:
            div = n // 2 + 1
            odd = True
        row1 = nums[ : div]
        row2 = nums[div :]
        row1.reverse()
        row2.reverse()
        for i in range(div - 1):
            print(row1[i], row2[i], end = " ")
        
        if odd:
            print(row1[i + 1])
        else:
            print(row1[i + 1], row2[i + 1])