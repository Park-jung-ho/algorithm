import sys
input = sys.stdin.readline

N, S = map(int,input().split())
arr = [0] + list(map(int,input().split()))
st = 0
ed = 0
plus = 0
leng = N+2
for i in range(1,N+1):
    arr[i] += arr[i-1]
    while 1:
        if arr[i] - arr[st+1] >= S:    
            st += 1
        else:
            break
    if arr[i] - arr[st] >= S:
        leng = min(leng,i-st)

if leng == N+2:
    print(0)
else:
    print(leng)    
    