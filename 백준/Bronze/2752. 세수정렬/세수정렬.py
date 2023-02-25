import sys
input = sys.stdin.readline

a = list(map(int,input().split()))
a.sort()
print(' '.join(map(str,a)))
