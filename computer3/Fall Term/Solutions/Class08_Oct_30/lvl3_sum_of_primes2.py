import sys
input = sys.stdin.readline

maxv = int(1e5)
f = [False for i in range(maxv+1)]
psa = [0 for i in range(maxv+1)]
for i in range(2, maxv+1):
    psa[i] = psa[i-1]
    if not f[i]:
        psa[i] += i
        for j in range(2*i, maxv+1, i):
            f[j] = True
for _ in range(int(input())):
    x, y = map(int, input().split())
    print(psa[y] - psa[x-1])