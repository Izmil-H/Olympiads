import sys
input = sys.stdin.readline
N, W = map(int, input().split())
maxv = int(1e5)
dp = [float('inf')] * (maxv+1)
dp[0] = 0
for i in range(N):
    w, v = map(int, input().split())
    for j in range(maxv, v-1, -1):
        dp[j] = min(dp[j], dp[j-v] + w)
for i in range(maxv, 0, -1):
    if dp[i] <= W:
        print(i)
        break