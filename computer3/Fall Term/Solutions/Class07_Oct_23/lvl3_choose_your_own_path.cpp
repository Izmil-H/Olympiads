#include <bits/stdc++.h>
using namespace std;
const int MM = 10003;
int N, dis[MM], cnt=1, ans=0x3f3f3f3f; bool ed[MM], vis[MM]; vector<int> adj[MM];
int main(){
    scanf("%d", &N);
    if(N==1) { printf("Y\n1\n"); return 0;}
    for(int i=1, m, x; i<=N; i++){
        scanf("%d", &m); ed[i] = (m==0);
        for(int j=0; j<m; j++){
            scanf("%d", &x);
            adj[i].push_back(x);
        }
    }
    queue<int> Q;
    Q.push(1); vis[1]=true; dis[1] = 1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v]=true; dis[v] = dis[u]+1; Q.push(v); cnt++;
                if(ed[v]) ans = min(ans, dis[v]);
            }
        }
    }
    if(cnt == N) printf("Y\n%d\n", ans);
    else printf("N\n%d\n", ans);
}