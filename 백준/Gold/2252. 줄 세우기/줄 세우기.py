from collections import defaultdict, deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
node = [0] + [0 for _ in range(1,N+1)]
dic = defaultdict(list)
for _ in range(M):
    a, b = map(int,input().split())
    node[b] += 1
    dic[a].append(b)
queue = deque()

for i in range(1,N+1):
    if node[i] == 0:
        queue.append(i)
res = []
while queue:
    n = queue.popleft()
    res.append(n)
    for i in dic[n]:
        node[i] -= 1
        if node[i] == 0:
            queue.append(i)
print(' '.join(map(str,res)))