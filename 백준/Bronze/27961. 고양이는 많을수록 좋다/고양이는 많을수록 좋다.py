import sys
input = sys.stdin.readline


n = int(input())
if n < 2:
    print(n)
else:
    cnt = 2
    a = 2
    while 1:
        if a >= n:
            break
        cnt += 1
        a *= 2
    print(cnt)