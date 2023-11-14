import sys
input = sys.stdin.readline

def mpow(b,t,n):
    result = 1
    while t > 0:
        if t % 2 != 0:
            result = (result * b) % n
        t //= 2
        b = (b * b) % n

    return result

def mr(n,b,s,t):
    x = mpow(b,t,n)
    if x == 1 or x == n-1:
        return 1
    else:
        for i in range(s):
            x = mpow(x,2,n)
            if x == n-1:
                return 1
        return 0

def check(n):
    l = [2,7,61]
    s = 0
    if n<2:
        return 0
    if n<=100:
        if arr[n]:
            return 1
        return 0
    t = n-1
    while t%2==0:
        s += 1
        t = t//2
    for b in l:
        can = mr(n,b,s,t)
        if can == 0:
            return 0
    return 1
n = 100
arr = [True for _ in range(n+1)]
m = int(n**0.5)
for i in range(2,m+1):
    if arr[i] == True:
        for j in range(2*i,n+1,i):
            arr[j] = False

N = int(input())
count = 0
for _ in range(N):
    a = int(input())
    n = 2*a + 1
    if a < 4:
        count += 1
    elif check(n) == 1:
        count += 1
print(count)