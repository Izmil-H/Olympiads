from itertools import permutations
from sys import stdin
input = stdin.readline
n = int(input())
block = []
for i in range(4):
    block.append(input().strip())
for _ in range(n):
    word = input().strip()
    id = [0, 1, 2, 3]
    found = False
    for x in list(permutations(id)):
        flag = True
        for k in range(len(word)):
            if block[x[k]].find(word[k]) == -1:
                flag = False
                break
        if flag:
            found = True
            break
    print('YES') if found else print('NO')