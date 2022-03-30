#include <bits/stdc++.h>
using namespace std;
int N, M, adj[52][52], a[2500], b[2500]; bool vis[52];
bool bfs(){
    memset(vis, 0, sizeof(vis));
    queue<int> q;  q.push(1); vis[1]=1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<=N; v++){
            if(adj[u][v] && !vis[v]) { vis[v]=1; q.push(v); }
        }
    }
    return vis[N];
}
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i]; adj[a[i]][b[i]] = 1;
    }
    for(int i=0; i<M; i++){
        adj[a[i]][b[i]] = 0;
        cout << ( bfs()? "YES\n" : "NO\n");
        adj[a[i]][b[i]] = 1;
    }
}