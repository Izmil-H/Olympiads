import sys
from collections import deque
input = sys.stdin.readline
n, m = list(map(int, input().split()))
heights = {}
for i in range(m):
    x, y = list(map(int, input().split()))
    if x-1 in heights:
        heights[x-1].append(y-1)
    else:
        heights[x-1] = [y-1]
p, q = list(map(int, input().split()))
p-=1
q-=1

def bfs(p, q):
    queue = deque([p])
    NotVisited = [True for i in range(n)]
    NotVisited[p] = False
    while queue:
        cur = queue.popleft()
        if cur == q:
            return True
        if cur in heights:
            for x in heights[cur]:
                if NotVisited[x]:
                    queue.append(x)
                    NotVisited[x] = False
    return False

if bfs(p, q):
    print('yes')
elif bfs(q, p):
    print('no')
else:
    print('unknown')