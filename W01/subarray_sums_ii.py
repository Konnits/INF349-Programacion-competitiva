class Element:
    def __init__(self):
        self.prefix_sum = {0 : 1}
        self.count = 0
        self.current_sum = 0

def make(num, element, value):
    element.current_sum += num
    element.count, element.prefix_sum[element.current_sum]= element.count + element.prefix_sum.get(element.current_sum - value, 0), element.prefix_sum.get(element.current_sum, 0) + 1


n,value = map(int, input().split())
arr = list(map(int,input().split()))

element = Element()

[make(num, element, value) for num in arr]

print(element.count)