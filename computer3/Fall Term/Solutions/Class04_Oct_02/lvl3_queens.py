import sys
input = sys.stdin.readline
n, m = map(int, input().split())
row, col, left, right = [True]*n, [True]*n, [True]*(2*n-1), [True]*(2*n-1)
for _ in range(m):
    r, c = map(int, input().split())
    r, c = r-1, c-1
    row[r] = col[c] = left[r+c] = right[r+n-1-c] = False
ans = 0
for r in range(n):
    for c in range(n):
        if row[r] and col[c] and left[r+c] and right[r+n-1-c]:
            ans+=1
print(ans)