from itertools import permutations
s = input()
perm = list(permutations(s))
perm.sort()
for x in perm:
    print(''.join(x))