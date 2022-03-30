import sys
input = sys.stdin.readline
n = int(input())
def fun(x):
    if x > n:
        return 0
    return fun(x*10+2) + fun(x*10+3) + 1
print(fun(2) + fun(3))