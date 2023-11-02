import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())
cnt = 0
for i in range(n):
    a = input().rstrip()
    if '01' in a or 'OI' in a:
        cnt += 1
print(cnt)