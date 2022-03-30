import sys
input = sys.stdin.readline
n = int(input())
cow = list(map(int, input().split()))
stall = list(map(int, input().split()))
cow.sort(reverse=True)
stall.sort(reverse=True)
ans = 1
for i in range(n):
    cnt = 0
    for j in range(i, n):
        if stall[j] >= cow[i]:
            cnt += 1
    ans = ans*cnt
print(ans)