import sys
input = sys.stdin.readline

# 맵 출력
def show(die):
    # print('>> MAP | me : (%d,%d)'%(HERO['lo'][0],HERO['lo'][1]))
    tmp = MAP[HERO['lo'][0]][HERO['lo'][1]] 
    if die == 0:
        MAP[HERO['lo'][0]][HERO['lo'][1]] = '@'
    for a in MAP:
        print(''.join(a))
    MAP[HERO['lo'][0]][HERO['lo'][1]] = tmp

# 레벨 업
def LVUP():
    HERO['LV'] += 1
    HERO['EXP'] = -HERO['LV']*5
    HERO['HP'][1] += 5
    HERO['HP'][0] = HERO['HP'][1]
    HERO['ATT'] += 2
    HERO['DEF'] += 2

# 정보 입력받기
N, M = map(int,input().split())
MAP = []
HERO = {'lo':[0,0],
        'HP':[20,20],
        'ATT':2,
        'W':0,
        'DEF':2,
        'A':0,
        'EXP':-5,
        'LV':1,
        'ITEM':[]}

K = 0
L = 0
startpoint = 0
for i in range(N):
    a = list(input().rstrip())
    for j in range(M):
        if a[j] == '@':
            HERO['lo'] = [i,j]
            startpoint = [i,j]
            a[j] = '.'
        elif a[j] == 'M':
            K += 1
        elif a[j] == '&':
            K += 1
        elif a[j] == 'B':
            L += 1
    MAP.append(a)

# 움직일 순서
MOVE = {'L':[0,-1],'R':[0,1],'U':[-1,0],'D':[1,0]}
IN = list(input().rstrip())

# 몬스터 정보 MONSTER[(x,y)] = [이름,공격력,방어력,체력,경험치]
MONSTER = {}
for i in range(K):
    info = list(input().split())
    x,y = map(int,info[:2])
    x, y = x-1, y-1
    MONSTER[(x,y)] = [info[2]]+list(map(int,info[3:]))

# 아이템 정보 ITEM[(x,y)] = [장비종류,값or이름]
ITEM = {}
for i in range(L):
    info = list(input().split())
    x,y = map(int,info[:2])
    x, y = x-1, y-1
    ITEM[(x,y)] = info[2:]

# 게임 진행
ending = 'Press any key to continue.'
Turns = 0
die = 0
for i in range(len(IN)):
    Turns += 1
    x, y = HERO['lo']
    nx = x + MOVE[IN[i]][0]
    ny = y + MOVE[IN[i]][1]
    # 못 움직이면 제자리 이동
    if nx < 0 or nx >= N or ny < 0 or ny >= M or MAP[nx][ny] == '#':
        nx, ny = x, y
    
    if MAP[nx][ny] == '.': # 빈칸이면 위치 업데이트 하고 이동
        HERO['lo'] = [nx,ny]
    elif MAP[nx][ny] == '^': # 가시
        if 'DX' in HERO['ITEM']:
            HERO['HP'][0] -= 1
        else:
            HERO['HP'][0] -= 5
        HERO['lo'] = [nx,ny]
        if HERO['HP'][0] <= 0:
            if 'RE' in HERO['ITEM']:
                HERO['ITEM'].remove('RE')
                HERO['HP'][0] = HERO['HP'][1]
                HERO['lo'] = startpoint
            else:
                HERO['HP'][0] = 0
                ending = 'YOU HAVE BEEN KILLED BY SPIKE TRAP..'
                die = 1
                break
    elif MAP[nx][ny] == 'B': # 아이템
        MAP[nx][ny] = '.'
        if ITEM[(nx,ny)][0] == 'W':
            HERO['W'] = int(ITEM[(nx,ny)][1])
        elif ITEM[(nx,ny)][0] == 'A':
            HERO['A'] = int(ITEM[(nx,ny)][1])
        elif ITEM[(nx,ny)][0] == 'O':
            if len(HERO['ITEM']) < 4 and ITEM[(nx,ny)][1] not in HERO['ITEM']:
                HERO['ITEM'].append(ITEM[(nx,ny)][1])
        HERO['lo'] = [nx,ny]
    elif MAP[nx][ny] == '&' or MAP[nx][ny] == 'M': # 몬스터
        win = 0
        M_HP = MONSTER[(nx,ny)][3]
        atkx2 = 0
        meetboss = 0
        if 'CO' in HERO['ITEM']:
            atkx2 = 1
        if 'HU' in HERO['ITEM'] and MAP[nx][ny] == 'M':
            meetboss = 1
        # 전투 시작
        while 1:
            if meetboss == 1:
                HERO['HP'][0] = HERO['HP'][1]
            # 주인공 턴
            if atkx2 == 1:
                if 'DX' in HERO['ITEM']: 
                    M_HP -= max(1,(HERO['ATT'] + HERO['W'])*3 - MONSTER[(nx,ny)][2])
                else:
                    M_HP -= max(1,(HERO['ATT'] + HERO['W'])*2 - MONSTER[(nx,ny)][2])
                atkx2 = 0
            else:
                M_HP -= max(1,HERO['ATT'] + HERO['W'] - MONSTER[(nx,ny)][2])

            if M_HP <= 0:
                win = 1
                break

            # 몬스터 턴
            if meetboss == 1:
                meetboss = 0
            else:
                HERO['HP'][0] -= max(1,MONSTER[(nx,ny)][1] - (HERO['DEF'] + HERO['A']))

            if HERO['HP'][0] <= 0:
                HERO['HP'][0] = 0
                break

        # 전투 후 정산
        if win == 1:
            if 'HR' in HERO['ITEM']:
                HERO['HP'][0] += 3
                if HERO['HP'][0] > HERO['HP'][1]:
                    HERO['HP'][0] = HERO['HP'][1]

            if 'EX' in HERO['ITEM']:
                HERO['EXP'] += int(MONSTER[(nx,ny)][4]*1.2)
            else:
                HERO['EXP'] += MONSTER[(nx,ny)][4]

            if HERO['EXP'] >= 0:
                LVUP()
                
            HERO['lo'] = [nx,ny]
            if MAP[nx][ny] == 'M':
                ending = 'YOU WIN!'
                break
            MAP[nx][ny] = '.'
        else:
            if 'RE' in HERO['ITEM']:
                HERO['ITEM'].remove('RE')
                HERO['HP'][0] = HERO['HP'][1]
                HERO['lo'] = startpoint
            else:
                ending = 'YOU HAVE BEEN KILLED BY '+ MONSTER[(nx,ny)][0] +'..'
                die = 1
                break
            
#게임 결과
show(die)
print('Passed Turns :',Turns)
print('LV :',HERO['LV'])
print('HP : %d/%d'%(HERO['HP'][0],HERO['HP'][1]))
print('ATT : %d+%d'%(HERO['ATT'],HERO['W']))
print('DEF : %d+%d'%(HERO['DEF'],HERO['A']))
print('EXP : %d/%d'%(HERO['LV']*5+HERO['EXP'],HERO['LV']*5))
print(ending)