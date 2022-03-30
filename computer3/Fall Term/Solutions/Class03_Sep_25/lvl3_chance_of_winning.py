import sys
input = sys.stdin.readline
T = int(input()) - 1
G = int(input())
pts = [0 for i in range(4)]
game = [(0,1), (0,2), (0,3), (1, 2), (1, 3), (2, 3)]
def solve( index ):
    if index == len(game):
        for i in range(4):
            if i != T and pts[i] >= pts[T]:
                return 0
        return 1
    way = 0
    a, b = game[index]
    pts[a] += 3
    way += solve(index + 1)
    pts[a] -= 3
    pts[b] += 3
    way += solve(index + 1)
    pts[b] -= 3
    pts[a], pts[b] = pts[a]+1, pts[b]+1
    way += solve(index + 1)
    pts[a], pts[b] = pts[a]-1, pts[b]-1
    return way

for i in range(G):
    a, b, pa, pb = map(int, input().split())
    a-=1; b-=1; game.remove((a, b))
    if pa > pb : 
        pts[a] += 3
    elif pa < pb :
        pts[b] += 3
    else:
        pts[a], pts[b] = pts[a]+1, pts[b]+1
print(solve(0))