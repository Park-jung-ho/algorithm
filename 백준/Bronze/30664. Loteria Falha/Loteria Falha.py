import sys
from collections import defaultdict
input = sys.stdin.readline

while 1:
    n = int(input())
    if (n == 0):
        break
    if (n%42 == 0):
        print("PREMIADO")
    else:
        print("TENTE NOVAMENTE")
