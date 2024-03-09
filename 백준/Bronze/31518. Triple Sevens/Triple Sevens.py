import sys
input = sys.stdin.readline

T = int(input())
cnt = 0
for i in range(3):
    arr = list(map(int,input().split()))
    if 7 in arr:
        cnt += 1
if cnt == 3:
    print(777)
else:
    print(0)