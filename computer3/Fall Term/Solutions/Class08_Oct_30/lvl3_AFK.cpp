#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int T; char g[51][51]; int moves[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}, dis[52][52];
bool vis[52][52];
int main(){
    scanf("%d", &T);
    while(T--) {
        int r, c; pii st, ed;
        memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &c, &r);
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                scanf(" %c", &g[i][j]);
                if(g[i][j] == 'C') st = make_pair(i, j);
                if(g[i][j] == 'W') ed = make_pair(i, j);
            }
        }
        queue<pii> q; q.push(st); vis[st.first][st.second] = 1;
        while(!q.empty()) {
            pii u = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nr = moves[i][0] + u.first, nc = moves[i][1] + u.second;
                if(nr < 1 || nc < 1 || nr > r || nc > c || vis[nr][nc] || g[nr][nc] == 'X')
                    continue;
                q.push({nr, nc}); vis[nr][nc] = 1; dis[nr][nc] = dis[u.first][u.second]+1;
            }
        }
        if(!vis[ed.first][ed.second] || dis[ed.first][ed.second] >= 60)
            cout << "#notworth\n";
        else cout << dis[ed.first][ed.second] << "\n";
    }
}