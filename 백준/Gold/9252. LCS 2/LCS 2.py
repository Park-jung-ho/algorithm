from pprint import pprint
import sys
input = sys.stdin.readline

b = list(input().rstrip())
a = list(input().rstrip())
al = len(a)
bl = len(b)
res = ''
dp = [[0 for _ in range(al+1)]for __ in range(bl+1)]
for i in range(1,bl+1):
    for j in range(1,al+1):
        if b[i-1] == a[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])

print(dp[-1][-1])
num = dp[-1][-1]
y = al
for i in range(bl,0,-1):
    for j in range(1,y+1):
        if dp[i][j] == num and dp[i][j] == dp[i-1][j]:
            continue
        if dp[i][j] == num and dp[i][j] == dp[i-1][j-1] + 1:
            res = a[j-1] + res
            y = j - 1
            num -= 1
            break        
print(res)