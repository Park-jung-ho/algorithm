import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
arr = list(map(int,input().split()))
j = N
jm = 0
for i in arr:
    if j >= i:
        jm += j//i
        j -= (j//i)*i
last = 0
stack = 0
uplast = 0
upstack = 0
s = N
sm = 0
sall = 0
for i in arr:
    if last == 0:
        last = i
        stack = 1
    else:
        if stack == 3:
            stack -= 1
            sm += s//i
            s -= (s//i)*i
            
        if last > i:
            stack += 1
            last = i
        else:
            stack = 1
            last = i

    if uplast == 0:
        uplast = i
        upstack = 1
    else:
        if upstack == 3 and sm != 0:
            upstack -= 1
            s += sm*i
            sm = 0
            
        if uplast < i:
            upstack += 1
            uplast = i
        else:
            upstack = 1
            uplast = i

a = jm*arr[-1]+j
b = sm*arr[-1]+s
if a == b:
    print('SAMESAME')
elif a > b:
    print('BNP')
else:
    print('TIMING')
    

