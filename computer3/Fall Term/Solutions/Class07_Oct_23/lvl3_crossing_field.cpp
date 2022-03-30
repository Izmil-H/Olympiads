#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1502;
int N, H, g[MM][MM], dir[4][2]={{-1,0}, {1,0}, {0,1}, {0,-1}}; bool vis[MM][MM];
int main(){
    cin >> N >> H;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> g[i][j];
    queue<pi> q; q.push({1, 1}); vis[1][1]=true;
    while(!q.empty()){
        int r = q.front().first, c = q.front().second; q.pop();
        for(int k=0; k<4; k++){
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if(nr>=1&&nr<=N && nc>=1 && nc<=N && !vis[nr][nc] && abs(g[nr][nc]-g[r][c])<=H){
                q.push({nr, nc}); vis[nr][nc]=true;
            }
        }
    }
    cout << (vis[N][N]? "yes": "no") << endl;
}