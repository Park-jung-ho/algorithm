import sys
input = sys.stdin.readline

N, M, x, y, K = map(int,input().split())
arr = []
for i in range(N):
    arr.append(list(map(int,input().split())))
move = list(map(int,input().split()))
dice = [0 for _ in range(7)]
res = []
dx = [0,0,0,-1,1]
dy = [0,1,-1,0,0]

for k in move:
    nx = x + dx[k]
    ny = y + dy[k]
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        continue
    if k == 1:
        dice[1],dice[3],dice[6],dice[4] = dice[4],dice[1],dice[3],dice[6]
    if k == 2:
        dice[1],dice[3],dice[6],dice[4] = dice[3],dice[6],dice[4],dice[1]
    if k == 3:
        dice[1],dice[5],dice[6],dice[2] = dice[5],dice[6],dice[2],dice[1]
    if k == 4:
        dice[1],dice[5],dice[6],dice[2] = dice[2],dice[1],dice[5],dice[6]
    if arr[nx][ny] == 0:
        arr[nx][ny] = dice[6]
    else:
        dice[6] = arr[nx][ny]
        arr[nx][ny] = 0
    res.append(dice[1])
    x, y = nx, ny


print('\n'.join(map(str,res)))