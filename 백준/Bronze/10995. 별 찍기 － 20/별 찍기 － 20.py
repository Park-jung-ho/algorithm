import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

for i in range(1,n+1):
    if i%2 == 0:
        print(' ',end='')
    for j in range(n):
        print('*',end=' ')
    print()