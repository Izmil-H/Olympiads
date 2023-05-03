from bisect import bisect_left
from sys import stdin
input = stdin.readline
n = int(input())
a = list(map(int, input().split()))
pos = [0]*int(1e6+1)
for i in range(n):
    pos[a[i]] = i+1
m = int(input())
lis = []
b = list(map(int, input().split()))
for x in b:
    x = pos[x]
    if x == 0: continue
    if len(lis) == 0 or x > lis[-1]:
        lis.append(x)
    else:
        lis[bisect_left(lis, x)] = x
print(len(lis))