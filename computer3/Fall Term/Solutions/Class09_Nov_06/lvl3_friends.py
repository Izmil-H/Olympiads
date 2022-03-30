import sys
input = sys.stdin.readline
n = int(input())
adj = [0 for _ in range(10000)]
for _ in range(n):
    x, y = map(int, input().split())
    adj[x] = y
while True:
    x, y = map(int, input().split())
    if x == 0 and y == 0:
        break
    length, start = 0, x
    vis = [0 for _ in range(10000)]
    while not vis[start] and start != y:
        vis[start] = True
        length += 1
        start = adj[start]
    if start == y:
        print("Yes", length-1)
    else:
        print("No")