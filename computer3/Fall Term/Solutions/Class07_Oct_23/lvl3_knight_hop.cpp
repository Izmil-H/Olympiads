#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int sx, sy, tx, ty, dis[9][9]; bool vis[9][9]; queue<pi> q;
int d[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int main(){
    cin >> sx >> sy >> tx >> ty;
    q.push({sx, sy}); vis[sx][sy]=true; dis[sx][sy]=0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second; q.pop();
        for(int k=0; k<8; k++) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if(nx < 1 || nx > 8 || ny < 1 || ny > 8 || vis[nx][ny]) continue;
            q.push({nx, ny}); vis[nx][ny]=true;
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
    cout << dis[tx][ty] << endl;
}