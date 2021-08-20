import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
l, r = 0, n-1
while l < r:
    print(arr[l], end=' ')
    if l+1 == r:
        print(arr[r], end='\n')
    else:
        print(arr[r], end=' ')
    l, r = l+1, r-1
if l == r:
    print(arr[l], end='\n')
for i in range(n//2):
    print('BS', end='')
print('E') if n%2 == 1 else print()