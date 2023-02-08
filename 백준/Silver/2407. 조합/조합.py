import sys
input = sys.stdin.readline

n, m = map(int,input().split())
num = 1
for i in range(m):
    num *= n-i
for i in range(m):
    num //= m-i
print(num)