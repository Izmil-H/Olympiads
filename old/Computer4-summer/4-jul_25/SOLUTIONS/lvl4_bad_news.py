import sys

input = sys.stdin.readline
n, q = map(int, input().split())
g, vis = [], []


def fun(r, c, idx, word):
    global n
    if idx == len(word):
        return True
    vis[r][c] = True
    for dr in range(-1, 2):
        for dc in range(-1, 2):
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= n or vis[nr][nc] or g[nr][nc] != word[idx]:
                continue
            if fun(nr, nc, idx + 1, word):
                return True
    return False


for i in range(n):
    g.append(input().strip().split())
for _ in range(q):
    word, found = input().strip(), False
    for r in range(n):
        for c in range(n):
            if g[r][c] == word[0]:
                vis = [[False] * n for i in range(n)]
                found = fun(r, c, 1, word)
            if found:
                break
        if found:
            break
    print('good puzzle!') if found else print('bad puzzle!')