import sys
from collections import deque
input = sys.stdin.readline

mod = int(1e9+7)
for _ in range(int(input())):
    a, b, c, k = map(int, input().split())
    if b-a == c - b:
        print( (a + (b-a)*(k-1))% mod )
    else:
        print( a * pow(b//a, k-1, mod) % mod )