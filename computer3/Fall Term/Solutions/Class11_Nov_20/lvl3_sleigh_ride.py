import sys
input = sys.stdin.readline
n = int(input())
places = [[] for i in range(n+1)]
sum = 0
for i in range(n):
    a, b, c = list(map(int, input().split(" ")))
    places[a].append((b, c))
    sum += 2*c

def dfs(u, p):
    mx = 0
    for v, w in places[u]:
        if v == p:
            continue
        mx = max(mx, dfs(v, u) + w)
    return mx
print(sum - dfs(0, -1))