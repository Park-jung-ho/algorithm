import sys
input = sys.stdin.readline

T = int(input())
PT = []

def how(target):
    if len(dic[target]) == 0: 
        dp[target] = Di[target-1]
        return dp[target]
    time = 0
    for i in dic[target]:
        if dp[i] == -1:
            time = max(time,how(i))
        else:
            time = max(time,dp[i])
    dp[target] = time + Di[target-1]
    return dp[target]

for _ in range(T):
    N, k = map(int,input().split())
    Di = list(map(int,input().split()))
    dic = {i:[] for i in range(1,N+1)}
    dp = [-1]*(N+1)
    for i in range(k):
        x, y = map(int,input().split())
        dic[y].append(x)
    end = int(input())

    PT.append(how(end))
print('\n'.join(map(str,PT)))
