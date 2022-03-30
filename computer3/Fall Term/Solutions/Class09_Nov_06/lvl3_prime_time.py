import sys
import math
input = sys.stdin.readline

for _ in range(5):
    n = int(input())
    f = [0] * (n+1)
    for i in range(2, n+1):
        x = i
        for j in range(2, int(math.sqrt(x))+1):
            while x % j == 0:
                f[j] += 1
                x //= j
        if x != 1:
            f[x] += 1
    first = True
    for i in range(2, n+1):
        if f[i] > 0 :
            if first:
                print(i, '^', f[i], ' ', sep='', end='')
                first = False
            else:
                print('* ', i, '^', f[i], ' ', sep='', end='')
    print()