import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())
can = 1
lst = ['Never gonna give you up',
       'Never gonna let you down',
       'Never gonna run around and desert you',
       'Never gonna make you cry',
       'Never gonna say goodbye',
       'Never gonna tell a lie and hurt you',
       'Never gonna stop']

for i in range(n):
    a = input().rstrip()
    if a not in lst:
        can = 0
if can == 0:
    print('Yes')
else:
    print('No')