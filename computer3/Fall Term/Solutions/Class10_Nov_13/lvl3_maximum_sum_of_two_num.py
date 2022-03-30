import sys
from bisect import bisect_right
input = sys.stdin.readline
n, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
ans = 0
for i in range(n):
    p = bisect_right(a, m-a[i], 0, i)-1
    if p >= 0:
        ans = max(ans, a[p] + a[i])
print(ans)