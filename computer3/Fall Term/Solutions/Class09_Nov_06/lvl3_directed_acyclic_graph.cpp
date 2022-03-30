#include <bits/stdc++.h>
using namespace std;
int n, adj[1002][1002], vis[1002]; bool cycle;
void dfs(int u){
    vis[u] = 1;
    for(int v=1; v<=n; v++){
        if(adj[u][v] == 1){
            if(vis[v] == 0) dfs(v);
            else if(vis[v] == 1) cycle=true;
        }
    }
    vis[u] = 2;
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> adj[i][j];
    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i);
    cout << (cycle? "NO": "YES") << endl;
}