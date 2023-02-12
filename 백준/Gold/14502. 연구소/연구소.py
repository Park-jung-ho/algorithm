from collections import deque
import sys
input = sys.stdin.readline



N, M = map(int,input().split())
res = 0
board = []
b = []
line = []
for i in range(N):
    a = list(map(int,input().split()))
    for j in range(M):
        line.append((i,j))
        if a[j] == 2:
            b.append((i,j))
    board.append(a)


def BFS():
    global b
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1] 
    queue = deque(b)
    visit = [[0 for _ in range(M)] for __ in range(N)]
    
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx < 0 or nx >= N or ny < 0 or ny >= M:                
                continue
            if board[nx][ny] == 1:
                continue
            if visit[nx][ny] == 0:
                visit[nx][ny] = 1
                queue.append((nx,ny))
    cnt = 0
    for i in range(N):
        for j in range(M):
            if visit[i][j] == 0 and board[i][j] == 0:
                cnt += 1
    return cnt
def make(x,w): 
    global res   
    if w == 3:
        res = max(res,BFS())
        return

    for k in range(x,N*M):
        i, j = line[k]
        if board[i][j] == 0:
            board[i][j] = 1
            make(k,w+1)
            board[i][j] = 0

make(0,0)
print(res)