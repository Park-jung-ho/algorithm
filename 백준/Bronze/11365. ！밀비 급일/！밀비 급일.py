import sys
from collections import defaultdict
input = sys.stdin.readline
while 1:
    a = input().rstrip()
    if a == 'END':
        break
    a = list(a)
    a.reverse()
    print(''.join(a))