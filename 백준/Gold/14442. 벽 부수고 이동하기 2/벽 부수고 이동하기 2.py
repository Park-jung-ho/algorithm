from collections import deque
import sys
input = sys.stdin.readline

n, m , can = map(int, input().split())
board = [list(map(int, input().rstrip())) for _ in range(n)]

x = 0
y = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1] 
visit = [[[0]*(can+1) for col in range(m)] for row in range(n)]
visit[0][0][0] = 1

queue = deque()
queue.append((x,y,0,1))

while queue:
    x, y, count, total = queue.popleft()
    if x == n-1 and y == m-1:
        print(total)
        sys.exit(0)
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:                
            continue
        if board[nx][ny] == 1 and count < can:
            if visit[nx][ny][count+1] == 0:
                visit[nx][ny][count+1] = total + 1
                visit[x][y][count+1] = total + 1
                queue.append((nx,ny,count+1,total+1))
        elif board[nx][ny] == 0:
            if visit[nx][ny][count] == 0:
                visit[nx][ny][count] = total + 1
                queue.append((nx,ny,count,total+1))
            

print(-1)