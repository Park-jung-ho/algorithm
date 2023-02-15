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

for _ in range(M):
    t, a, b = map(int,input().split())
    if t == 0:
        union(a,b)
    elif t == 1:
        ar = findroot(a)
        br = findroot(b)
        if ar == br:
            print('YES')
        else:
            print('NO')
                