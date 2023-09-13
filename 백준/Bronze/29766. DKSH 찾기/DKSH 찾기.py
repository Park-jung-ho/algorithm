import sys
from collections import defaultdict
input = sys.stdin.readline

a = input().rstrip()
dk = 'DKSH'
cnt = 0
for i in range(len(a)-3):
    if a[i:i+4] == dk:
        cnt += 1
print(cnt)