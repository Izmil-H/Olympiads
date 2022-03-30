import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
tree = [[] for i in range(n+1)]
for i in range(n-1):
    x, y = list(map(int, input().split(" ")))
    tree[x].append(y)
    tree[y].append(x)

def bfs(start, dstLst):
    queue = deque()
    queue.append(start)
    dstLst[start] = 1
    longEnd = -1
    while len(queue) != 0:
        cur = queue.popleft()
        longEnd = cur
        for v in tree[cur]:
            if dstLst[v] == -1:
                queue.append(v)
                dstLst[v] = dstLst[cur] + 1
    return longEnd
dstA = [-1 for i in range(n+1)]
endA = bfs(1, dstA)
dstA = [-1 for i in range(n+1)]
endB = bfs(endA, dstA)
dstB = [-1 for i in range(n+1)]
bfs(endB, dstB)

for i in range(1, n+1):
    print(max(dstA[i], dstB[i]))