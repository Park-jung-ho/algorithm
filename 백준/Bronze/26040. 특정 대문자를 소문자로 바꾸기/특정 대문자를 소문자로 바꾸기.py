import sys
input = sys.stdin.readline

a = input().rstrip()
b = list(input().split())
for c in a:
    if c in b:
        c = c.lower()
    print(c,end='')