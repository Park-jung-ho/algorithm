import sys
from heapq import heappop, heappush
input = sys.stdin.readline

N, L = map(int, input().split())
Ai = list(map(int,input().split()))

heap = []
result = []
for i in range(N):
    heappush(heap,(Ai[i],i))
    while heap[0][1] < i-L+1:
        heappop(heap)
    result.append(heap[0][0])
print(' '.join(map(str,result)))