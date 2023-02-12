from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input().rstrip()) for _ in range(N)]

queue = deque()

dx = [-1,1,0,0]
dy = [0,0,-1,1]

for i in range(N):
    for j in range(M):
        if board[i][j] == 'R':
            rx = i
            ry = j
        if board[i][j] == 'B':
            bx = i
            by = j


def move(x,y,x2,y2,i):
    goal = 0
    while 1:
        nx = x + dx[i]
        ny = y + dy[i]

        if board[nx][ny] == 'O':
            x = nx
            y = ny
            goal = 1
            break
        if board[nx][ny] == '#':
            break
        if nx == x2 and ny == y2:
            break
        x = nx
        y = ny
    return x,y,goal
c = 0
can = 0
visit = set()
queue.append([rx, ry, bx, by,0,visit])
visit.add((rx, ry, bx, by))
def game():
    while queue:
        rx, ry, bx, by, c, visit = queue.popleft()
        
        for i in range(4):
            if rx == bx:
                if i == 2:
                    if ry < by:
                        nrx,nry,gR = move(rx,ry,bx,by,i)
                        nbx,nby,gB = move(bx,by,nrx,nry,i)
            
                    elif ry > by:
                        nbx,nby,gB = move(bx,by,rx,ry,i)
                        nrx,nry,gR = move(rx,ry,nbx,nby,i)
                elif i == 3:
                    if ry < by:
                        nbx,nby,gB = move(bx,by,rx,ry,i)
                        nrx,nry,gR = move(rx,ry,nbx,nby,i)
            
                    elif ry > by:
                        nrx,nry,gR = move(rx,ry,bx,by,i)
                        nbx,nby,gB = move(bx,by,nrx,nry,i)
                else:
                    nrx,nry,gR = move(rx,ry,bx,by,i)
                    nbx,nby,gB = move(bx,by,nrx,nry,i)
            elif ry == by:
                if i == 0:
                    if rx < bx:
                        nrx,nry,gR = move(rx,ry,bx,by,i)
                        nbx,nby,gB = move(bx,by,nrx,nry,i)
            
                    elif rx > bx:
                        nbx,nby,gB = move(bx,by,rx,ry,i)
                        nrx,nry,gR = move(rx,ry,nbx,nby,i)
                elif i == 1:
                    if rx < bx:
                        nbx,nby,gB = move(bx,by,rx,ry,i)
                        nrx,nry,gR = move(rx,ry,nbx,nby,i)
            
                    elif rx > bx:
                        nrx,nry,gR = move(rx,ry,bx,by,i)
                        nbx,nby,gB = move(bx,by,nrx,nry,i)
                else:
                    nrx,nry,gR = move(rx,ry,bx,by,i)
                    nbx,nby,gB = move(bx,by,nrx,nry,i)
            else:
                nrx,nry,gR = move(rx,ry,bx,by,i)
                nbx,nby,gB = move(bx,by,nrx,nry,i)
            
            if rx == nrx and ry == nry:
                if bx == nbx and by == nby:
                    continue
                elif (nbx,nby,nbx,nby) in visit:
                    continue
            elif bx == nbx and by == nby:
                if rx == nrx and ry == nry:
                    continue
                elif (nrx,nry,nbx,nby) in visit:
                    continue
                
            if gR == 1 and gB == 0:
                return print(c+1)
                
            if gB == 1:
                continue
            
            if (nrx,nry,nbx,nby) not in visit:
                visit.add((nrx,nry,nbx,nby))
                queue.append((nrx,nry,nbx,nby,c+1,visit))


    if can == 0:
        print(-1)    

game()