def swap(arr, pos):
    if arr[pos] == "0":
        arr[pos] = "1"
    else:
        arr[pos] = "0"

def operations(n, op = []):
    if n == 1:
        return [1]
    else:
        prev = operations(n-1, op)
        return prev + [n] + prev
    
n = int(input())
arr = ["0"] * n

op = operations(n)

for move in op:
    print("".join(arr))
    swap(arr, n - move)
print("".join(arr))