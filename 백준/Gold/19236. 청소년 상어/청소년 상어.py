import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def fish_move():
    global arr, fish
    # print('fish move')
    for i in range(1,17):
        if fish[i][0] == -1:
            continue
        x, y = fish[i][0],fish[i][1]
        m = arr[x][y][1]
        for _ in range(8):
            if m >= 9:
                m = 1
            nx = dx[m] + x
            ny = dy[m] + y
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
                m += 1
                continue
            if arr[nx][ny][0] == -1:
                m += 1
                continue
            arr[x][y] = [arr[nx][ny][0],arr[nx][ny][1]]
            fish[arr[x][y][0]] = [x,y]
            arr[nx][ny] = [i,m]
            fish[i] = [nx,ny]
            break

def shark_move(x,y):
    global cnt, res, arr, fish
    # print(*arr,sep='\n')
    fish_move()
    now = [[j[:] for j in i] for i in arr]
    # print('--------')
    # print(*arr,sep='\n')
    nowfish = [i[:] for i in fish]
    m = arr[x][y][1]
    fx, fy = x, y
    for _ in range(3):
        nx = dx[m] + x
        ny = dy[m] + y
        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:    
            break
        if arr[nx][ny][0] == 0:
            x, y = nx, ny
            continue
        p = arr[nx][ny][0]
        cnt += p
        fish[p] = [-1,-1]
        arr[nx][ny][0] = -1
        arr[fx][fy] = [0,0]
        shark_move(nx,ny)
        cnt -= p
        arr = [[j[:] for j in i] for i in now]
        fish = [i[:] for i in nowfish]
        x, y = nx, ny
    res = max(res,cnt)
    return

arr = []
fish = [[-1,-1] for _ in range(17)]
for i in range(4):
    a = list(map(int,input().split()))
    for k in range(0,7,2):
        fish[a[k]] = [i,k//2]
    arr.append([a[:2],a[2:4],a[4:6],a[6:8]])

res = 0
cnt = 0
fish[arr[0][0][0]] = [-1,-1]
cnt += arr[0][0][0]
arr[0][0][0] = -1


dx = [0,-1,-1, 0, 1,1,1,0,-1]
dy = [0,0, -1,-1,-1,0,1,1,1]


# print(*arr,sep='\n')
shark_move(0,0)
print(res)