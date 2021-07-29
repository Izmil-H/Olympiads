import sys
input = sys.stdin.readline
n = int(input())
h = list(map(int, input().split()))
stk, ans = [], []
for i in range(n):
    while len(stk) > 0 and h[stk[-1]] <= h[i]:
        stk.pop()
    if len(stk) == 0:
        ans.append(i)
    else:
        ans.append(i - stk[-1])
    stk.append(i)
print(*ans, sep=' ')