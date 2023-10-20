import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())
for i in range(n):
    a = input().rstrip()
    for c in a:
        print(c.lower(),end='')
    print()