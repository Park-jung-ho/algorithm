import sys
input = sys.stdin.readline

a, b = map(int,input().split())
alist = []
for i in range(a-1):
    alist.append(int(input()))
blist = list(map(int,input().split()))

if a != 1:
    mina = min(alist)
else:
    mina = blist[0]
    alist = [mina]
minb = min(blist)
if mina == 0:
    print(alist.index(mina)+1,1)
elif minb == 0:
    print(a,blist.index(minb)+1)
else:
    print(alist.index(mina)+1,mina+1)