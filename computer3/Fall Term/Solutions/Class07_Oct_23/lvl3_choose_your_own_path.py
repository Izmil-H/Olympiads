import sys
input = sys.stdin.readline
n = int(input())
adj = [[]]
for i in range(1, n+1):
    adj.append(list(map(int, input().split()))[1:])
q, dis = [], [0 for i in range(0, n+1)]
q.append(1) 
dis[1] = 1
cnt = 0
while len(q) > 0:
    cur = q.pop(0)
    cnt += 1
    for v in adj[cur]:
        if dis[v] == 0:
            dis[v] = dis[cur] + 1
            q.append(v)
print('Y') if cnt == n else print('N')
ans = n + 1
for i in range(1, n+1):
    if len(adj[i]) == 0 and dis[i] > 0:
        ans = min(ans, dis[i])
print(ans)