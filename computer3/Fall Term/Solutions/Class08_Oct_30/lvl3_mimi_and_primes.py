import sys
import math
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
g, ans = 0, 0
for x in a:
    g = math.gcd(g, x)
for i in range(2, int(math.sqrt(g))+1):
    while g % i == 0:
        ans, g = i, g//i
if g != 1:
    ans = g
print(ans) if ans > 0 else print('DNE')