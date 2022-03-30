import sys
input = sys.stdin.readline
T = int(input())
for t in range(T):
    n = int(input())
    m = int(input())
    g = [input().strip() for i in range(n)]
    dis = [ [0 for c in range(m)] for r in range(n)]
    q = [(0, 0)]
    dis[0][0] = 1
    while len(q):
        r, c = q.pop(0)
        if g[r][c] == '+':
            if r-1>=0 and g[r-1][c]!='*' and dis[r-1][c]==0:  # move up
                q.append((r-1, c))
                dis[r-1][c] = dis[r][c] + 1
            if r+1<n and g[r+1][c]!='*' and dis[r+1][c]==0:  # move down
                q.append((r+1, c))
                dis[r+1][c] = dis[r][c] + 1
            if c-1>=0 and g[r][c-1]!='*' and dis[r][c-1]==0:  # move left
                q.append((r, c-1))
                dis[r][c-1] = dis[r][c] + 1
            if c+1<m and g[r][c+1]!='*' and dis[r][c+1]==0:  # move up
                q.append((r, c+1))
                dis[r][c+1] = dis[r][c] + 1
        elif g[r][c] == '|':
            if r-1>=0 and g[r-1][c]!='*' and dis[r-1][c]==0:  # move up
                q.append((r-1, c))
                dis[r-1][c] = dis[r][c] + 1
            if r+1<n and g[r+1][c]!='*' and dis[r+1][c]==0:  # move down
                q.append((r+1, c))
                dis[r+1][c] = dis[r][c] + 1
        elif g[r][c] == '-':
            if c-1>=0 and g[r][c-1]!='*' and dis[r][c-1]==0:  # move left
                q.append((r, c-1))
                dis[r][c-1] = dis[r][c] + 1
            if c+1<m and g[r][c+1]!='*' and dis[r][c+1]==0:  # move up
                q.append((r, c+1))
                dis[r][c+1] = dis[r][c] + 1
    print(dis[n-1][m-1]) if dis[n-1][m-1] > 0 else print(-1)