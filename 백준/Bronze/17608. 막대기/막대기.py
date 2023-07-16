import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    a = int(input())    
    arr.append(a)
arr.reverse()
a = 0
cnt = 0
for i in range(n):
    if arr[i] > a:
        cnt += 1
        a = arr[i]
print(cnt)