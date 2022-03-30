import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
n, q = map(int, input().split())
p = [i for i in range(n+1)]

def find(d):
    if p[d] != d:
        p[d] = find(p[d])
    return p[d]

for i in range(q):
    x = input().split()
    if x[0] == 'A':
        p[find(int(x[1]))] = find(int(x[2]))
    else:
        print('Y' if find(int(x[1]))==find(int(x[2])) else 'N')