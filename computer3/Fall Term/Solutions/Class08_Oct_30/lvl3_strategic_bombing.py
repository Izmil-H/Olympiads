from sys import stdin
lines = []
ans = []
while True:
    line = stdin.readline().strip()
    lines.append(line)
    if line == '**':
        break

def bfs (graph, start, goal, visited):
    visited = []
    queue = graph[start].copy()

    while len(queue) != 0:
        cur = queue.pop(0)

        for neighbour in graph[cur]:
            if neighbour == goal:
                return True

            if neighbour not in visited:
                queue.append(neighbour)
                visited.append(neighbour)

    

    return False



paths = {}
for i in range(ord('A'), ord('Z')+1):
    paths[chr(i)] = []
for i in range(0, len(lines)-1):
    query = list(lines[i])
    x = query[0]
    y = query[1]
    paths[x].append(y)
    paths[y].append(x)

ans = []
tried = []
for i in range(0, len(lines)-1):
    query = list(lines[i])
    x = query[0]
    y = query[1]
    if x+y not in tried:
        
        tried.append(x+y)
        tried.append(y+x)

        paths[x].remove(y)
        paths[y].remove(x)
        
        test = bfs(paths, 'A', 'B', ['A'])
        if test == False:
            ans.append(x+y)
            
        paths[x].append(y)
        paths[y].append(x)

if len(ans) == 0:
    print('There are 0 disconnecting roads.')
    
else:
    for i in range(0, len(ans)):
        print(ans[i])
    print('There are '+str(i+1)+' disconnecting roads.')