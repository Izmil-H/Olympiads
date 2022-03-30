from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    vis = set()
    sum = 0
    for x in a:
        sum += x
        vis.add(sum)
    if sum == 0:
        print(0)
        continue
    ans = n+1
    for len in range(n, 0, -1):
        if sum % len != 0:
            continue
        val, flag = sum // len, True
        for x in range(val, sum+1, val):
            if x not in vis:
                flag = False
                break
        if flag:
            ans = n - len
            break
    print(ans)