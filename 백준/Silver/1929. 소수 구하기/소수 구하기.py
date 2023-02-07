from sys import stdin

m, n = list(map(int, stdin.readline().split()))
def prime(n):
    arr = [True for _ in range(n+1)]
    m = int(n**0.5)
    for i in range(2,m+1):
        if arr[i] == True:
            for j in range(2*i,n+1,i):
                arr[j] = False
    return [i for i in range(2,n+1) if arr[i]==True]

a = prime(n)

for i in a:
    if i >= m:
        print(i)