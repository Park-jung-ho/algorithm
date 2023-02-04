import sys
input = sys.stdin.readline

N = int(input())
def prime(n):
    arr = [True for _ in range(n+1)]
    m = int(n**0.5)
    for i in range(2,m+1):
        if arr[i] == True:
            for j in range(2*i,n+1,i):
                arr[j] = False
    return [i for i in range(2,n+1) if arr[i]==True]

arr = [0] + prime(N)
st = 0

total = 0
for i in range(1,len(arr)):
    arr[i] += arr[i-1]
    while 1:
        if arr[i] - arr[st+1] > N:    
            st += 1
        elif arr[i] - arr[st+1] == N:
            st += 1
            break
        else:
            break
    if arr[i] - arr[st] == N:
        total += 1
print(total)