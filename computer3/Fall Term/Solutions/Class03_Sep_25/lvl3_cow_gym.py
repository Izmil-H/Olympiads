k, n = map(int, input().split())
l = []
for i in range(k):
    l.append(list(map(int, input().split())))
cnt = 0
for i in range(1, n+1):
    for j in range(i+1, n+1):
        flag = True
        for r in range(k-1):
            posi, posj = l[r].index(i), l[r].index(j)
            nxti, nxtj = l[r+1].index(i), l[r+1].index(j)
            if (posi-posj) * (nxti-nxtj) < 0:
                flag = False
        if flag:
            cnt += 1
print(cnt)