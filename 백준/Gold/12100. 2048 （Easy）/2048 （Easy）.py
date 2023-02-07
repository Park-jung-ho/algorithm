import sys
input = sys.stdin.readline

N = int(input())
board = []
MAXNUM = 0
for i in range(N):
    board.append(list(map(int,input().split())))

def game(n,new):
    global MAXNUM
    P = new
    if n == 5:
        for arr in P:
            MAXNUM = max(MAXNUM,max(arr))
        return

    for M in range(4):
        if M == 0: # left
            newL = []
            for i in range(N):
                update = []
                lc = 0
                for j in range(N):
                    if P[i][j] == 0:
                        continue
                    if len(update) == 0:
                        update.append(P[i][j])
                    else:
                        if P[i][j] == update[-1] and lc == 0:
                            update[-1] *= 2
                            lc = 1
                        else:
                            update.append(P[i][j])
                            lc = 0
                if len(P[i]) > len(update):
                    update += [0]*(len(P[i]) - len(update))
                newL.append(update)
            if newL != P:
                game(n+1,newL)
        if M == 1: # right
            newR = []
            for i in range(N):
                update = []
                lc = 0
                for j in range(N-1,-1,-1):
                    if P[i][j] == 0:
                        continue
                    if len(update) == 0:
                        update.append(P[i][j])
                    else:
                        if P[i][j] == update[-1] and lc == 0:
                            update[-1] *= 2
                            lc = 1
                        else:
                            update.append(P[i][j])
                            lc = 0
                if len(P[i]) > len(update):
                    update += [0]*(len(P[i]) - len(update))
                update.reverse()

                newR.append(update)
            if newR != P:
                game(n+1,newR)   
        if M == 2: # up
            newU = [[0 for _ in range(N)] for __ in range(N)]
            for j in range(N):
                update = []
                lc = 0
                for i in range(N):
                    if P[i][j] == 0:
                        continue
                    if len(update) == 0:
                        update.append(P[i][j])
                    else:
                        if P[i][j] == update[-1] and lc == 0:
                            update[-1] *= 2
                            lc = 1
                        else:
                            update.append(P[i][j])
                            lc = 0
                for i in range(len(update)):
                    newU[i][j] = update[i]    
            if newU != P:
                game(n+1,newU)    
        if M == 3: # down
            newD = [[0 for _ in range(N)] for __ in range(N)]
            for j in range(N):
                update = []
                lc = 0
                for i in range(N-1,-1,-1):
                    if P[i][j] == 0:
                        continue
                    if len(update) == 0:
                        update.append(P[i][j])
                    else:
                        if P[i][j] == update[-1] and lc == 0:
                            update[-1] *= 2
                            lc = 1
                        else:
                            update.append(P[i][j])
                            lc = 0
                for i in range(len(update)):
                    newD[N-1-i][j] = update[i]    
            if newD != P:
                game(n+1,newD)    
    for arr in P:
        MAXNUM = max(MAXNUM,max(arr))
game(0,board)
print(MAXNUM)