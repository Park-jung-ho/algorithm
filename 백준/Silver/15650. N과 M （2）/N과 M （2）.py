import sys
input = sys.stdin.readline

N, M = map(int,input().split())
s = []
visited = set()
def NM():
    if len(s) == M:
        if tuple(set(s)) not in visited:
            print(' '.join(map(str,s)))
            visited.add(tuple(set(s)))
        return
    
    visit = set(s)
    for i in range(1,N+1):
        if i not in visit:
            s.append(i)
            NM()
            s.pop()

NM()