import sys
input = sys.stdin.readline

arr = [0 for i in range(int(1e7))]
n = int(input())
last, mx = 0, 0
for i in range(n):
    s, f = map(int, input().split())
    arr[s] += 1
    arr[f] -= 1
    last = max(last, f)
for i in range(last):
    arr[i] += arr[i-1]
    mx = max(mx, arr[i])
print(mx)