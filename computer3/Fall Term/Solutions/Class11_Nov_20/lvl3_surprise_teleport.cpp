#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
int R, C, T, dis[1002][1002], d[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, tr, tc, MIN;
pii st, ed; bool g[1002][1002], vis[1002][1002]; char ch;
void bfs(){
    queue<pii> Q;
    Q.push(st); dis[st.x][st.y]=0; vis[st.x][st.y]=1;
    while(!Q.empty()){
        int r=Q.front().x, c=Q.front().y; Q.pop();
        for(int i=0; i<4; i++){
            int nr=r+d[i][0], nc=c+d[i][1];
            if(nr>=0&&nr<R&&nc>=0&&nc<C&&!vis[nr][nc]&&!g[nr][nc]){
                dis[nr][nc]=dis[r][c]+1;
                Q.push(make_pair(nr, nc));
                vis[nr][nc]=1;
            }
        }
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    cin >> R >> C >> st.x >> st.y >> ed.x >> ed.y;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            cin >> ch;
            g[i][j] = (ch=='X');
        }
    bfs();
    cin >> T; MIN=dis[ed.x][ed.y];
    while(T--){
        cin >> tr >> tc;
        if(vis[tr][tc]) MIN = min(MIN, dis[tr][tc]);
    }
    cout << dis[ed.x][ed.y]-MIN << endl;
}