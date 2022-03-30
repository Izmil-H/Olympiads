#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, st, far, dia, cnt; vector<int> adj[MM]; bool pho[MM];
void dfs1(int u, int pa){
    for(int v: adj[u]){
        if(v == pa) continue;
        dfs1(v, u);
        if(pho[v]) pho[u] = true;
    }
}
void dfs2(int u, int pa, int dis){
    if(dis > dia) { dia = dis; far = u; }
    for(int v : adj[u]){
        if(v == pa || !pho[v]) continue;
        dfs2(v, u, dis+1);
    }
}
int main(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> st; pho[st] = true;
    }
    for(int i=1, u, v; i<N; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(st, -1); dfs2(st, -1, 0); dia=0; dfs2(far, -1, 0);
    for(int i=0; i<N; i++)
        if(pho[i]) cnt++;
    cout << 2*(cnt-1) - dia << endl;
}