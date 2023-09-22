import sys
from collections import defaultdict
input = sys.stdin.readline
N = int(input())
for i in range(N):
    a = input().rstrip()
    if a == 'Algorithm':
        print(204)
    if a == 'DataAnalysis':
        print(207)
    if a == 'ArtificialIntelligence':
        print(302)
    if a == 'CyberSecurity':
        print('B101')
    if a == 'Network':
        print(303)
    if a == 'Startup':
        print(501)
    if a == 'TestStrategy':
        print(105)