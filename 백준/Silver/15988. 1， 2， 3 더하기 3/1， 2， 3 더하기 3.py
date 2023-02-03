import sys
input = sys.stdin.readline

T = int(input())
dp = [0 for _ in range(1000001)]
def tile(n):
    dp[1] = 1
    if n == 1:
        return print(1)
    dp[2] = 2
    if n == 2:
        return print(2)
    dp[3] = 4
    if n == 3:
        return print(4)
    for i in range(4,n+1):
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009
        
tile(1000000)
Ta = []    
for i in range(T):
    n = int(input())
    Ta.append(dp[n])
print('\n'.join(map(str,Ta)))