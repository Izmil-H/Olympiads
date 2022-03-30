import sys
import bisect
input = sys.stdin.readline

n, m = map(int, input().split())
a = [[False]*(n+1) for i in range(n+1)]
count = 0
for _ in range(m):
    x, y = map(int, input().split())
    a[x][y] = a[y][x] = True

def getcomb(i, comb):
    global count
    if i > n:
        count+=1
        return
    getcomb(i+1, comb)

    valid = True
    for x in comb:
        if a[x][i]:
            valid = False
    if valid:
        comb.append(i)
        getcomb(i+1, comb)
        comb.pop()

getcomb(1, [])
print(count)