import sys
from collections import deque
input = sys.stdin.readline
m, n = map(int, input().split())
sr, sc = map(int, input().split())
er, ec = map(int, input().split())
g = []
dis = [[-1]*n for i in range(m)]
q = deque()
for i in range(m):
    g.append(input().strip())
d = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1), (-1, 0), (1, 0), (0, -1), (0, 1)]
q.append((sr-1, sc-1))
dis[sr-1][sc-1] = 0
while len(q):
    r, c = q.popleft()
    for dr, dc in d:
        nr, nc = r + dr, c + dc
        if nr < 0 or nr >= m or nc < 0 or nc >= n or g[nr][nc] == '#' or dis[nr][nc] != -1:
            continue
        q.append((nr, nc))
        dis[nr][nc] = dis[r][c] + 1
print(dis[er-1][ec-1])