import sys
input = sys.stdin.readline
N, L = map(int, input().split())
lst, sol = [], []

def recurse(lvl, word):
    global N, L, sol
    if lvl == N or len(word) == L :
        sol.append(word)
        return
    for j in range(len(lst[lvl])):
        recurse(lvl+1, word+lst[lvl][j])

for i in range(N):
    line = input().strip().split()
    line2 = line[1:]
    if i != 0:
        line2.append("")
    lst.append(line2)
recurse(0, "")
sol.sort()
for s in sol:
    print(s)