import sys
input = sys.stdin.readline

N = int(input())

dp = [[0 for _ in range(10)] for __ in range(N+1)]
for i in range(1,10):
    dp[1][i] = 1
dp[0][1] = 1
for i in range(2,N+1):
    dp[i][1] = (dp[i-2][1] + dp[i-1][2])%1000000000
    dp[i][9] = dp[i-1][8]
    for j in range(2,9):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000
    
print(sum(dp[N])%1000000000)
