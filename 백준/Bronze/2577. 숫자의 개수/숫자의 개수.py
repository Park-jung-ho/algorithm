import sys
from collections import defaultdict
input = sys.stdin.readline

a = int(input())
b = int(input())
c = int(input())
d = a*b*c
d = str(d)
a = [0 for _ in range(10)]
for i in d:
    a[int(i)] += 1
print('\n'.join(map(str,a)))