import sys
input = sys.stdin.readline
n, t = map(int, input().split())
m = int(input())
p = []
for i in range(m):
    p.append(tuple(map(int, input().split())))
cur, time, count, ans, up = 0, 0, 0, 0, True
inElevator, done = [-1]*m, [False]*m
while count < m:
    for i in range(m):
        if done[i]:
            continue
        if cur == p[i][1] and inElevator[i]==-1 and p[i][0] <= time:
            inElevator[i] = time
            ans += time - p[i][0]
        elif cur == p[i][2] and inElevator[i] != -1:
            done[i] = True
            count+=1
            ans += time - inElevator[i]
    if cur == 0:
        up = True
    if cur == n:
        up = False
    if up:
        cur += 1
    else:
        cur -= 1
    time += t
print(ans)