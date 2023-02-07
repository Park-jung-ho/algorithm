import sys
input = sys.stdin.readline
arr = []
while 1:
    a = int(input())
    if a == 0:
        break
    arr.append(a)
a = max(arr)*2
s = [True] * (a+1)
for i in range(2,int(a**(1/2))+1):
    if s[i] == True:
        for j in range(2*i,a+1,i):
            s[j] = False
res = []
for a in arr:
    c = 0
    for i in range(a+1,(2*a)+1):
        if s[i] == True:
            c += 1
    res.append(c)
print('\n'.join(map(str,res)))