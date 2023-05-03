from itertools import combinations
import sys
input = sys.stdin.readline
n, k = map(int, input().split())
for _ in range(k):
    s, t, r = map(int, input().split())
    time, tot = 0, n
    while tot > s*t:
        time += t + r
        tot -= s*t
    time += (tot + s - 1)//s
    print(time)