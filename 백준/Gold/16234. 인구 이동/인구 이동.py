from collections import deque
import sys
input = sys.stdin.readline

N, L, R = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
queue = deque()
def show():
    for i in arr:
        print(' '.join(map(str,i)))

# show()
cnt = 0
while 1:
    
    visit = [[0 for _ in range(N)] for __ in range(N)]
    nomove = 0
    for i in range(N):
        for j in range(N):
            if visit[i][j] == 1:
                continue
            queue.append((i,j))
            group = set()
            group.add((i,j))
            groupsum = arr[i][j]
            visit[i][j] = 1
            while queue:
                x, y = queue.popleft()

                for k in range(4):
                    nx = dx[k] + x
                    ny = dy[k] + y
                    if nx < 0 or nx >= N or ny < 0 or ny >= N:
                        continue
                    if visit[nx][ny] == 1:
                        continue
                    if abs(arr[x][y] - arr[nx][ny]) >= L and abs(arr[x][y] - arr[nx][ny]) <= R:
                        group.add((nx,ny))
                        groupsum += arr[nx][ny]
                        visit[nx][ny] = 1
                        queue.append((nx,ny))
            if len(group) == 1:
                nomove += 1
                continue
            gn = groupsum // len(group)
            for g in group:
                x, y = g[0],g[1]
                arr[x][y] = gn
            # show()
    if nomove == N*N:
        print(cnt)
        break
    cnt += 1