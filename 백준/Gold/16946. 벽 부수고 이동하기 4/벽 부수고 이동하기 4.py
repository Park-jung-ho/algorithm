from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
board = []
result = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]
for _ in range(N):
    board.append(list(map(int,input().rstrip())))
zero = {}
group = 2
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            queue = deque()
            queue.append((i,j))
            visit = set()
            visit.add((i,j))
            while queue:
                x, y = queue.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx < 0 or nx >= N or ny < 0 or ny >= M:
                        continue
                    if board[nx][ny] != 0:
                        continue
                    if (nx,ny) not in visit:
                        queue.append((nx,ny))
                        visit.add((nx,ny))
            count = len(visit)
            zero[group] = count
            for x, y in visit:
                board[x][y] = group
            group += 1
  
for i in range(N):
    arr = []
    for j in range(M):
        if board[i][j] == 1:
            visit = set()
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if nx < 0 or nx >= N or ny < 0 or ny >= M:
                    continue
                if board[nx][ny] == 1:
                    continue
                visit.add(board[nx][ny])
            add = 1
            for v in visit:
                add += zero[v]
            arr.append(add%10)
        else:
            arr.append(0)
    result.append(arr)
for i in result:
    print(''.join(map(str,i)))