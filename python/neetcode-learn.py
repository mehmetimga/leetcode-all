# assignment variable
n = 0
n = None
print('n', n)

n = 'abc'
print('n', n)

n = 1
# if conditions
if n > 2:
    n -= 1
elif n == 1:
    n += 1
else:
    n += 4

print('n', n)
# while loop
n = 0

while n < 5:
    print(n)
    n += 1

print('for loop')
# for loop
for i in range(5):
    print(i)

print('for loop reverse')
for i in range(5, 0, -1):
    print(i)

print('division')
print(5 / 2)
print(5 // 2)
print(-3 // 2)
print(int(-3 / 2))

# Mod
print(10 % 3)
print(-10 % 3)

import math

print(math.fmod(-10, 3))
print(math.floor(3 / 2))  # round down
print(math.ceil(3 / 2))  # round up
print(math.sqrt(2))
print(math.pow(2, 3))

# Max/Min int
print(float("inf"))
print(float("-inf"))
print(math.pow(2, 200))

# arrays
arr = [1, 2, 3]
print(arr)

arr.append(4)
arr.append(5)
print(arr)

arr.pop()
print(arr)

arr.insert(1, 7)
print(arr)

arr[1] = 9
print(arr)

# initializing array
n = 5
arr = [1] * n
print(arr)
print(len(arr))

# reverse index array
arr = [1, 2, 3, 4, 5]
print(arr[-1])
print(arr[-2])
# sublist (aka slicing
print(arr[1:3])
print(arr[2:])
print(arr[:3])

# loop through arrays
print('loop through arrays')
for i in range(len(arr)):
    print(i)

print('without index')
for i in arr:
    print(i)

print('enumerate')
for i, n in enumerate(arr):
    print(i, n)

print('loop through multiple array')
nums1 = [1, 2, 3]
nums2 = [4, 5, 6, 7]

for i, k in zip(nums1, nums2):
    print(i, k)

print('reverse array')
arr.reverse()
print(arr)

print('sort array')
arr.sort()
print(arr)

print('sort reverse array')
arr.sort(reverse=True)
print(arr)

print('srint array sort')
arr = ["bob", "alice", "jane", "doe"]
arr.sort()
print(arr)

arr.reverse()
print('sorted function')
print(sorted(arr, key=str.lower))

print('custom sort by length')
arr.sort(key=lambda x: len(x))
print(arr)

print('list comprehension')
arr = [i + i for i in range(5)]
print(arr)

# strings
print(int("123") + int("123"))
print(str(123) + str(123))

# ascii value
print(ord("a"))
print(ord("b"))

# join strings
strings = ["ab", "cd", "ef"]
print("".join(strings))
print("-".join(strings))

print('quees\n')
from collections import deque

queue = deque()
queue.append(1)
queue.append(2)
print(queue)

queue.popleft()
print(queue)

queue.appendleft(4)
print(queue)

queue.pop()
print(queue)

queue.append(9)
queue.appendleft(7)

queue.popleft()
print(queue)

# Hashset
print('HashSet')
mySet = set()

mySet.add(1)
mySet.add(2)
mySet.add(3)
print(mySet)

print(1 in mySet)
print(6 in mySet)

if 1 in mySet:
    print('correct')

if 4 not in mySet:
    print('correct')

print('map')
a = {}
a["alice"]= 5
print("alice" in a)

a = {"alice": 6, "bob": 70}
print(a['alice'])

print('looping maps')
for key in a:
    print(key,a[key])

for val in a.values():
    print(val)

for key,val in a.items():
    print(key,val)
#find min in heap
print('heap min')
import heapq
minHeap = []

heapq.heappush(minHeap, 80)
heapq.heappush(minHeap, 8)
heapq.heappush(minHeap, 3)
heapq.heappush(minHeap, 4)
heapq.heappush(minHeap, 5)

print(minHeap)
while len(minHeap):
    print(heapq.heappop(minHeap))

#functions and localval
print('function and localval')
def double(arr,val):
    def helper():
        for i, n in enumerate(arr):
            arr[i] *= 2

        nonlocal val
        val *= 2
    helper()
    print(arr,val)

nums=[1,2,3]
val=3
double(nums,val)

class MyClass:
    #Constructor
    def __init__(self,nums):
        self.nums = nums
        self.size = len(nums)

    def getLength(self):
        return self.size

    def getDoubleLength(self):
        return 2*self.getLength()

a=MyClass([1,2,3])
print('MyClass length=', a.getDoubleLength())