import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def findroot(x):
    if root[x] != x:
        root[x] =  findroot(root[x])
    return root[x]

def union(a,b):
    a = findroot(a)
    b = findroot(b)
    if a < b:
        root[b] = a
    else:
        root[a] = b

N, M = map(int,input().split())
root = [0] + [i for i in range(1,N+1)]
cnt = 0
node = []
for _ in range(M):
    a, b, c = map(int,input().split())
    node.append((c,a,b))
node.sort()    
for c, a, b in node:
    if findroot(a) == findroot(b):
        continue    
    union(a,b)
    cnt += c
print(cnt)
