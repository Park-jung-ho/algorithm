from collections import defaultdict
import sys
input = sys.stdin.readline

R, C, M = map(int, input().split())
shark = {}
res = 0
sea = [[0 for _ in range(C+1)] for __ in range(R+1)]
for i in range(1,M+1):
    shark[i] = list(map(int, input().split()))
    sea[shark[i][0]][shark[i][1]] = i
for c in range(1,C+1):
    for j in range(1,R+1):
        if sea[j][c] != 0:
            res += shark[sea[j][c]][4]
            del shark[sea[j][c]]
            sea[j][c] = 0
            break
    for i in shark.keys():
        sea[shark[i][0]][shark[i][1]] = 0
        if shark[i][3] == 1:    # 위
            speed = shark[i][2] + R - shark[i][0]
            if (speed // (R-1)) % 2 == 0:
                shark[i][0] = R - speed % (R-1)
            else:
                shark[i][0] = 1 + speed % (R-1)
                shark[i][3] = 2
        elif shark[i][3] == 2:    # 아래
            speed = shark[i][2] + shark[i][0] - 1
            if (speed // (R-1)) % 2 == 0:
                shark[i][0] = 1 + speed % (R-1)
            else:
                shark[i][0] = R - speed % (R-1)
                shark[i][3] = 1
        elif shark[i][3] == 3:    # 오른쪽
            speed = shark[i][2] + shark[i][1] - 1
            if (speed // (C-1)) % 2 == 0:
                shark[i][1] = 1 + speed % (C-1)
            else:
                shark[i][1] = C - speed % (C-1)
                shark[i][3] = 4
        elif shark[i][3] == 4:    # 왼쪽
            speed = shark[i][2] + C - shark[i][1]
            if (speed // (C-1)) % 2 == 0:
                shark[i][1] = C - speed % (C-1)
            else:
                shark[i][1] = 1 + speed % (C-1)
                shark[i][3] = 3
    cut = []
    for i in shark.keys():
        if sea[shark[i][0]][shark[i][1]] != 0:
            k = sea[shark[i][0]][shark[i][1]] 
            if shark[k][-1] < shark[i][-1]:
                sea[shark[i][0]][shark[i][1]] = i
                cut.append(k)
            else:
                cut.append(i)
        else:
            sea[shark[i][0]][shark[i][1]] = i
    for i in cut:
        del shark[i]
print(res)