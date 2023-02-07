import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int,input().split()))

res = []
for i in range(N-1):
    start = i+1
    end = N-1
    while 1:
        if start >= end:
            if len(res) == 0:
                res = [abs(arr[i]+arr[start]),arr[i],arr[start]]
            else:
                if abs(arr[i]+arr[start]) < res[0]:
                    res = [abs(arr[i]+arr[start]),arr[i],arr[start]]
            break
        mid = (start+end)//2
        if len(res) == 0:
                res = [abs(arr[i]+arr[mid]),arr[i],arr[mid]]
        else:
            if abs(arr[i]+arr[mid]) < res[0]:
                res = [abs(arr[i]+arr[mid]),arr[i],arr[mid]]
        if arr[i] + arr[mid] == 0:
            out = [arr[i],arr[mid]]
            out.sort()
            print(' '.join(map(str,out)))
            sys.exit(0)
        elif arr[i] + arr[mid] > 0:
            end = mid-1
        else:
            start = mid + 1
out = res[1:]
out.sort()
print(' '.join(map(str,out)))
