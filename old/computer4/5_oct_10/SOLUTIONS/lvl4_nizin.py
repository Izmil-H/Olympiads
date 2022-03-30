from collections import deque
n = int(input())
array = list(map(int, input().split(" ")))
a = deque(array)

count = 0
while len(a) > 1:
    if a[0] == a[-1]:
        a.popleft()
        a.pop()
    else:
        count += 1
        if a[0] > a[-1]:
            right = a.pop()
            a[-1] += right
        else:
            left = a.popleft()
            a[0] += left
print(count)