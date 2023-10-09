import sys
from collections import defaultdict
input = sys.stdin.readline

a = input().rstrip()
b = list(map(int,a.split('/')))

if b[0]+b[2] >= b[1] and b[1] != 0:
    print('gosu')
else:
    print('hasu')