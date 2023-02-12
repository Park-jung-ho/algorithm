from collections import deque, defaultdict
import sys
input = sys.stdin.readline

N, M = map(int,input().split())

move = defaultdict(int)
for i in range(N+M):
    a, b = map(int,input().split())
    move[a] = b

visit = [0 for _ in range(101)]
queue = deque()
queue.append((1,0))
visit[1] = 1
while queue:
    n, cnt = queue.popleft()

    if n == 100:
        print(cnt)
        sys.exit(0)
    
    for i in range(1,7):
        if n+i > 100:
            continue 
        if move[n+i] == 0 and visit[n+i] == 0:
            visit[n+i] = 1
            queue.append((n+i,cnt + 1))
        elif move[n+i] != 0 and visit[move[n+i]] == 0:
            visit[move[n+i]] = 1
            queue.append((move[n+i],cnt + 1))

