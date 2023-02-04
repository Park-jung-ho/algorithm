from sys import stdin

n, k = list(map(int, stdin.readline().split()))
dp = [[0 for _ in range(n)] for _ in range(k+1)]

for i in range(n):
    w, v = map(int, stdin.readline().split())
    dp[0][i] = [w, v]

dp[0].sort()

for j in range(n):
    w, v = dp[0][j]
    for i in range(1,k+1):
        if w > i:
            dp[i][j] = 0
        elif w == i:
            dp[i][j] = v
        else:
            if j == 0:
                dp[i][j] = v
            else:
                dp[i][j] = max(dp[i - w][:j]) + v

print(max(dp[-1]))