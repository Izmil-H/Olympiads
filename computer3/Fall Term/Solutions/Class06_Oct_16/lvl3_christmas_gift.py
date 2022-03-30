n, tot = map(int, input().split())
item = []
for i in range(n):
    item.append(list(map(int, input().split())))
ans = 0
for i in range(n):
    item[i][0] //= 2
    tmp = item.copy()
    tmp.sort(key=lambda x: x[0]+x[1])
    cnt, rem = 0, tot
    for x in tmp:
        if rem >= x[0] + x[1]:
            cnt+=1
            rem-=x[0] + x[1]
    ans = max(ans, cnt)
    item[i][0] *= 2
print(ans)