n = int(input())
i, cnt = 1, 0
while i <= n:
    if i*10 >= n:
        cnt += n - i + 1
    else:
        cnt += 9*i
    i *= 100
print(cnt)