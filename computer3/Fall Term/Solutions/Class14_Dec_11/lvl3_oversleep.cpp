#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int R, C, dis[1002][1002], r0, c0, r1, c1; char g[1002][1002]; queue<pii> Q;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    memset(dis, -1, sizeof(dis));
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        scanf("%s", g[i]);
        for(int j=0; j<C; j++)
            if(g[i][j]=='s') {r0=i; c0=j;}
            else if(g[i][j]=='e') {r1=i; c1=j;}
    }
    Q.push(make_pair(r0, c0)); dis[r0][c0]=0;
    while(!Q.empty()){
        int r=Q.front().first, c=Q.front().second; Q.pop();
        for(int k=0; k<4; k++){
            int nr=r+d[k][0], nc=c+d[k][1];
            if(nr>=0 && nr<R && nc>=0 && nc<C && g[nr][nc]!='X' && dis[nr][nc]<0){
                Q.push(make_pair(nr, nc)); dis[nr][nc]=dis[r][c]+1;
            }
        }
    }
    if(dis[r1][c1]<0) printf("-1\n");
    else printf("%d\n", dis[r1][c1]-1);
}