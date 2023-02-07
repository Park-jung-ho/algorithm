import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int,input().split()))
arr.reverse()
dp = [1] * (N+1)

for i in range(2,N+1):
    mn = 0
    for j in range(1,i+1):
        if arr[i-1] > arr[j-1]:
            mn = max(mn,dp[j])
    dp[i] += mn 
print(max(dp))