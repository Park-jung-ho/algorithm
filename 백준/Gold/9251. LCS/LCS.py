import sys
input = sys.stdin.readline

b = list(input().rstrip())
a = list(input().rstrip())
res = set()
al = len(a)
bl = len(b)
ml = min(al,bl)
dp = [[0 for _ in range(al+1)]for __ in range(bl+1)]
for i in range(1,bl+1):
    mn = 0
    for j in range(1,al+1):
        if b[i-1] == a[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
            mn = dp[i][j]
        else:
            dp[i][j] = max(dp[i-1][j],mn)
print(dp[-1][-1])