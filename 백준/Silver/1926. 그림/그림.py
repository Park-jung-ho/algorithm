import sys
from collections import deque
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]


n, m = map(int,input().split())
arr = []

for i in range(n):
    arr.append(list(map(int,input().split())))

visit = [[0 for _ in range(m)] for __ in range(n)]

cnt1 = 0
cnt2 = 0

for i in range(n):
    for j in range(m):
        if visit[i][j] == 1 or arr[i][j] == 0:
            continue
        cnt1 += 1
        queue = deque()
        queue.append((i,j))
        visit[i][j] = 1
        b = 1
        while queue:
            x, y = queue.popleft()
            for k in range(4):
                nx = dx[k] + x
                ny = dy[k] + y

                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                if visit[nx][ny] == 1:
                    continue
                if arr[nx][ny] == 1:
                    queue.append((nx,ny))
                    visit[nx][ny] = 1
                    b+=1
        cnt2 = max(cnt2,b)




print(cnt1)
print(cnt2)            

