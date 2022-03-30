import sys
input = sys.stdin.readline
n, a, b = map(int, input().split())
print((n+1)//2*a + n//2*b)