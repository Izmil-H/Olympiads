import sys
input = sys.stdin.readline
n, k = map(int, input().split())
maxn = 1e5
maxn = int(maxn)
row = [0 for i in range(maxn)]
col = [0 for i in range(maxn)]
d1 = [0 for i in range(2*maxn)]
d2 = [0 for i in range(2*maxn)]
output = -1
for i in range(n):
    xi, yi = map(int, input().split())
    xi-=1
    yi-=1
    col[xi] += 1
    row[yi] += 1
    d1[xi-yi+maxn] += 1
    d2[xi+yi] += 1
    if col[xi]==k or row[yi]==k or d1[xi-yi+maxn]==k or d2[xi+yi]==k:
        output = i+1
        break
print(output)