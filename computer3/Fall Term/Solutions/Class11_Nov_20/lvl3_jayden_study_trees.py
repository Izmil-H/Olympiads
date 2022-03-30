import sys
input = sys.stdin.readline

n = int(input())
tree = [[] for i in range(n+1)]
for i in range(n-1):
    x, y = map(int, input().split())
    tree[x].append(y)
    tree[y].append(x)

far = 0
dis = [-1]*(n+1)
q = [1]
dis[1] = 0
while len(q) > 0:
    far = q.pop(0)
    for nxt in tree[far]:
        if dis[nxt] == -1:
            q.append(nxt)
            dis[nxt] = dis[far] + 1

dis = [-1]*(n+1)
q = [far]
dis[far] = 0
while len(q) > 0:
    far = q.pop(0)
    for nxt in tree[far]:
        if dis[nxt] == -1:
            q.append(nxt)
            dis[nxt] = dis[far] + 1

print(dis[far])