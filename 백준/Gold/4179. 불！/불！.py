from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
arr = []
J = 0
F = []
visit = [[0 for _ in range(M)] for __ in range(N)]

for i in range(N):
    a = list(input().rstrip())
    for j in range(M):
        if a[j] == 'J':
            a[j] = '.'
            J = ['J',i,j]
            visit[i][j] = 1
        elif a[j] == 'F':
            a[j] = '.'
            F.append((i,j))
            visit[i][j] = 1
    arr.append(a)

queue = deque(F)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1] 

queue.append(J)

while queue:
    if queue[0][0] != 'J':
        x, y = queue.popleft()

        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue               
            if arr[nx][ny] == '#':
                continue
            if visit[nx][ny] > 0:
                continue
            if arr[nx][ny] == '.':
                visit[nx][ny] = 1
                queue.append((nx,ny))
    else:
        me, x, y = queue.popleft()

        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                # for a in visit:
                #     print(''.join(map(str,a))) 
                print(visit[x][y])
                sys.exit(0)               
            if arr[nx][ny] == '#':
                continue
            if visit[nx][ny] > 0:
                continue
            if arr[nx][ny] == '.':
                visit[nx][ny] = visit[x][y] + 1
                queue.append((me,nx,ny))
    



# for a in visit:
#     print(''.join(map(str,a)))         
print('IMPOSSIBLE')

