import sys
sys.setrecursionlimit(5000)

def get_sequence(m, nums, sequence = [], sum_left = 0, sum_right = 0, prev = None, i = 0, no_consider = set()):

    aux_prev = prev

    if (i == m and len(no_consider) == m - 2) or len(sequence) == m:
        return sequence

    aux_sequence = list(sequence)

    aux = set(map(lambda x : x if x > abs(sum_left - sum_right) else float("inf"), nums)) - {prev, float("inf")} - no_consider

    if len(aux) == 0:
        return aux_sequence

    num = min(aux)

    if i % 2 == 0:
        sum_left += num
    else:
        sum_right += num
    
    aux_sequence.append(str(num))
    prev = num

    new_sequence = get_sequence(m, nums, aux_sequence, sum_left, sum_right, prev, i + 1)

    if len(new_sequence) == m:
        return new_sequence
    
    else:
        if i % 2 == 0:
            sum_left -= num
        else:
            sum_right -= num
        
        no_consider = set(no_consider)

        no_consider.add(num)
        
        new_sequence = get_sequence(m, nums, sequence, sum_left, sum_right, aux_prev, i, no_consider)

    return new_sequence

weights = input()
m = int(input())

nums = set()

for i, digit in enumerate(weights):
    if digit == "1":
        nums.add(i + 1)

sequence = get_sequence(m, nums)

if len(sequence) == m:
    print("YES")
    print(" ".join(sequence))
else:
    print("NO")