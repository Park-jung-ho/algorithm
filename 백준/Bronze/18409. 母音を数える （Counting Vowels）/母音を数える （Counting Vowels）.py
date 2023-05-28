import sys
input = sys.stdin.readline

a = int(input())
arr = input().rstrip()
ar = ['a','e','o','u','i']
cnt = 0
for i in arr:
    if i in ar:
        cnt += 1
print(cnt)