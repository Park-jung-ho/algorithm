import sys
input = sys.stdin.readline

T = int(input())

arr = [0 for _ in range(10001)]
arr[1] = 1
arr[2] = 1

for i in range(2,T+1):
    arr[i] = arr[i-1] + arr[i-2]
print(arr[T])