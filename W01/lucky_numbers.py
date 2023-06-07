def get_super_luky(num, digits):
    if digits % 2 == 1:
        return [4] * ((digits + 1) // 2) + [7] * ((digits + 1) // 2)
    else:
        if num[0] > 7:
            return [4] * ((digits + 2) // 2) + [7] * ((digits + 2) // 2)
        else:
            cant_7 = 0
            cant_4 = 0
            higger = False
            for pos, digit in enumerate(num):
                if not higger and digit <= 4 and cant_4 < digits // 2:
                    if digit < 4:
                        higger = True
                    num[pos] = 4
                    cant_4 += 1
                elif not higger and digit <= 7  and cant_7 < digits // 2:
                    if digit < 7:
                        higger = True
                    num[pos] = 7
                    cant_7 += 1
                elif higger:
                    if cant_4 < digits // 2:
                        num[pos] = 4
                        cant_4 += 1
                    elif cant_7 < digits // 2:
                        num[pos] = 7
                        cant_7 += 1
                else:
                    if 4 in num[ : pos]:
                        pos_4 = digits - num[ : pos][:: - 1].index(4) - 1 - len(num[pos : ])
                        num[ pos_4 ] = 7
                        return get_super_luky(num[ : pos_4 + 1] + [0] * len(num[pos_4 + 1 : ]), digits)
                    else:
                        return [4] * ((digits + 2) // 2) + [7] * ((digits + 2) // 2)
            return num

num = list(map(int, list(input())))
digits = len(num)

print("".join(list(map(str,get_super_luky(num, digits)))))