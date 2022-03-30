#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5, LOG=19, mod = 998244353;
int N, Q, dep[MM], anc[MM][LOG]; vector<int> adj[MM]; long long pw[MM][51];
void dfs(int u, int pa, int d){
    dep[u] = d; anc[u][0] = pa; pw[u][0] = 1;
    for(int k=1; k<LOG; k++) anc[u][k] = anc[anc[u][k-1]][k-1];
    for(int k=1; k<=50; k++) pw[u][k] = pw[u][k-1] * (dep[u]-1) % mod;
    for(int k=1; k<=50; k++) pw[u][k] = (pw[u][k] + pw[pa][k])%mod;
    for(int v: adj[u])
        if(v != pa) dfs(v, u, d+1);
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k=LOG-1; k>=0; k--)
        if(dep[anc[u][k]] >= dep[v]) u = anc[u][k];
    if(u == v) return u;
    for(int k=LOG-1; k>=0; k--)
        if(anc[u][k] != anc[v][k]) u = anc[u][k], v = anc[v][k];
    return anc[u][0];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, u, v; i<N; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0, 1);  cin >> Q;
    for(int i=1, u, v, k; i<=Q; i++){
        cin >> u >> v >> k; int r = lca(u, v);
        cout << ((pw[u][k] + pw[v][k] - pw[r][k] - pw[anc[r][0]][k])%mod + mod ) %mod << "\n";
    }
}