from collections import defaultdict, deque
import sys
input = sys.stdin.readline

T = int(input())
dic = defaultdict(int)
tree = defaultdict(list)
queue = deque()
for i in range(T-1):
    n, m = map(int,input().split())
    tree[n].append(m)
    tree[m].append(n)
queue.append(1)
visit = set()
visit.add(1)
while queue:
    a = queue.popleft()
    for i in tree[a]:
        if i not in visit:
            visit.add(i)
            queue.append(i)
            dic[i] = a

res = []
for i in range(2,T+1):
    res.append(dic[i])
print('\n'.join(map(str,res)))