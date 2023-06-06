import sys
input = sys.stdin.readline
a = int(input())
b = int(input())

c = 8*a + 3*b - 28
if c >= 0:
    print(c)
else:
    print(0)