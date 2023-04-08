import sys
from collections import deque
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]


n = int(input())
arr = []

for i in range(n):
    arr.append(list(input().rstrip()))

visit = [[0 for _ in range(n)] for __ in range(n)]

cnt1 = 0
cnt2 = 0

for i in range(n):
    for j in range(n):
        if visit[i][j] == 1:
            continue
        cnt1 += 1
        queue = deque()
        queue.append((i,j))
        visit[i][j] = 1
        while queue:
            x, y = queue.popleft()
            for k in range(4):
                nx = dx[k] + x
                ny = dy[k] + y

                if nx < 0 or nx >= n or ny < 0 or ny >= n:
                    continue
                if visit[nx][ny] == 1:
                    continue
                if arr[nx][ny] == arr[i][j]:
                    queue.append((nx,ny))
                    visit[nx][ny] = 1

for i in range(n):
    for j in range(n):
        if arr[i][j] == 'R':
            arr[i][j] = 'G'

visit = [[0 for _ in range(n)] for __ in range(n)]

for i in range(n):
    for j in range(n):
        if visit[i][j] == 1:
            continue
        cnt2 += 1
        queue = deque()
        queue.append((i,j))
        visit[i][j] = 1
        while queue:
            x, y = queue.popleft()
            for k in range(4):
                nx = dx[k] + x
                ny = dy[k] + y

                if nx < 0 or nx >= n or ny < 0 or ny >= n:
                    continue
                if visit[nx][ny] == 1:
                    continue
                if arr[nx][ny] == arr[i][j]:
                    queue.append((nx,ny))
                    visit[nx][ny] = 1

print(cnt1,cnt2)            

