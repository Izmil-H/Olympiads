import sys
input = sys.stdin.readline

m = int(input())*2-1

count = {}

for i in range(0, m):
    query = input().strip()
    if query in count:
        count[query] += 1
    else:
        count[query] = 1
    
for key, value in count.items():
    if value%2 != 0:
        print(key)
        break