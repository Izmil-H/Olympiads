#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 6003, LOG = 13;
int N, Q, dep[MM], anc[LOG][MM]; ll dis[MM]; vector<pi> adj[MM];
void dfs(int u, int pa){
    anc[0][u] = pa;
    for(int k=1; k<LOG; k++) anc[k][u] = anc[k-1][anc[k-1][u]];
    for(pi e : adj[u]){
        int v = e.first , w = e.second;
        if(v == pa) continue;
        dep[v] = dep[u]+1; dis[v] = dis[u]+w; dfs(v, u);
    }
}
int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k=LOG-1; k>=0; k--)
        if(dep[anc[k][u]] >= dep[v]) u = anc[k][u];
    if(u == v) return u;
    for(int k=LOG-1; k>=0; k--)
        if(anc[k][u] != anc[k][v]) u = anc[k][u], v = anc[k][v];
    return anc[0][u];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w;   u++; v++;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0); cin >> Q;
    for(int i=1, u, v; i<=Q; i++) {
        cin >> u >> v;  u++; v++;
        cout << dis[u] + dis[v] - 2*dis[LCA(u, v)] << "\n";
    }
}