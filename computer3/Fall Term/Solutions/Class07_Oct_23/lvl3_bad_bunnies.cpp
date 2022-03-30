#include <bits/stdc++.h>
using namespace std;
const int MM = 200002;
int N, R, dis[MM], ans, pre[MM], x, y; bool vis[MM]; vector<int> adj[MM];
int main(){
    scanf("%d %d", &N, &R);
    for(int i=1, u, v; i<N; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    queue<int> Q;
    for(int i=0, u; i<R; i++){
        scanf("%d", &u); Q.push(u); vis[u]=1;
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int v: adj[cur]){
            if(!vis[v]){
                dis[v] = dis[cur]+1; vis[v]=1; Q.push(v);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &x, &y);
    Q.push(x); vis[x]=1; pre[x]=-1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int v: adj[cur]){
            if(!vis[v]){
                pre[v]=cur; vis[v]=1; Q.push(v);
            }
        }
    }
    ans = N+1;
    for(int u=y; u!=-1; u=pre[u])
        ans = min(ans, dis[u]);
    printf("%d\n", ans);
}