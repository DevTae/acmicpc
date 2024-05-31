result = sum([1,2,3,4,5])
print(result)

result = eval("(3+5)*7")
print(result)

result = sorted([4,7,3,1])
print(result)
result = sorted([4,7,3,1], reverse=True)
print(result)

result = sorted([('a',40), ('b',70), ('c',20)],
                key=lambda x:x[1], reverse=True)
print(result)


from itertools import combinations, combinations_with_replacement
from itertools import permutations

data = ['a', 'b', 'c']

result = list(combinations(data, 2))
print(result)

result = list(combinations_with_replacement(data, 2))
print(result)

result = list(permutations(data, 2))
print(result)


from itertools import product

data = ['a', 'b', 'c']

result = list(product(data, repeat=2))
print(result)


import heapq

def heapsort(iterable):
    h = []
    result = []
    for value in iterable:
        heapq.heappush(h, value)
    for i in range(len(h)):
        result.append(heapq.heappop(h))
    return result

result = heapsort([2,1,3,0,5,4])
print(result)


from bisect import bisect_left, bisect_right

a = [1,2,4,4,8]
x = 4

print(bisect_left(a,x))
print(bisect_right(a,x))


from collections import deque

data = deque([2,3,4])
print(data)
data.appendleft(1)
print(data)
data.popleft()
print(data)
data.append(5)
print(data)
print(list(data))


from collections import Counter

counter = Counter(['r', 'b', 'r', 'b', 'g', 'b'])

print(counter['b'])
print(counter['o'])
print(dict(counter))


import math

print(math.factorial(5))
print(math.sqrt(7))
print(math.gcd(21,14))
print(math.pi)
print(math.e)
