n = int(input())

def sugar(n):
    dp = [-1]*(n+1)
    dp[3] = 1
    if n >= 5:
        dp[5] = 1
    if n<6:
        return dp[n]
    for i in range(6,n+1):
        if dp[i-5] != -1:
            dp[i] = dp[i-5] + dp[5]
        elif dp[i-3] != -1:
            dp[i] = dp[i-3] + dp[3]
        else:
            dp[i] = -1
    return dp[n]

print(sugar(n))