T = int(input())
def tile(n):
    dp = [0 for _ in range(n+1)]

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
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        
    return print(dp[n])    
for i in range(T):
    n = int(input())
    tile(n)