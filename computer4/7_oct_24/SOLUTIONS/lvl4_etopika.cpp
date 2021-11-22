#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5, LOG = 17;
int N, D, dis[MM], dep[MM], lca[LOG][MM]; vector<pi> adj[MM]; ll dp[2];
void dfs(int u, int pa){
    lca[0][u] = pa;
    for(int i=1; i<LOG; i++) lca[i][u] = lca[i-1][lca[i-1][u]];
    for(pi e: adj[u]){
        if(e.f == pa) continue;
        dep[e.f] = dep[u] + 1; dis[e.f] = dis[u] + e.s; dfs(e.f, u);
    }
}
int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=LOG-1; i>=0; i--)
        if(dep[lca[i][x]] >= dep[y]) x = lca[i][x];
    if(x == y) return y;
    for(int i=LOG-1; i>=0; i--)
        if(lca[i][x] != lca[i][y]) x = lca[i][x], y = lca[i][y];
    return lca[0][x];
}
int dist(int u, int v){ return dis[u] + dis[v] - 2*dis[LCA(u, v)]; }
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &D);
    for(int i=1, u, v, w; i<N; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0); int l = 1, r = 1;
    for(int i=1, u, v; i<=D; i++){
        scanf("%d %d", &u, &v);
        ll dl = min(dp[0] + dist(l, v), dp[1] + dist(r, v)), dr =  min(dp[0] + dist(l, u), dp[1] + dist(r, u));
        dp[0] = dl + dist(v, u); dp[1] = dr + dist(u, v);
        l = u; r = v;
    }
    printf("%lld\n", min(dp[0], dp[1]));
}