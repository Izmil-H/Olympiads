from bisect import bisect_left
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
lis = []
for x in a:
    if len(lis) == 0 or x > lis[-1]:
        lis.append(x)
    else:
        lis[bisect_left(lis, x)] = x
print(len(lis))