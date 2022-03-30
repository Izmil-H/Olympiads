#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+4;
typedef pair<int, int> pi;
int n, mx, sum; vector<pi> adj[MM];
void dfs(int u, int p, int d) {
    if(d > mx) mx = d;
    for(pi e : adj[u]) {
        int v = e.first, w = e.second;
        if(v != p) dfs(v, u, d + w);
    }
}
int main(){
    cin >> n;
    for(int i=1, u, v, w; i<=n; i++) {
        cin >> u >> v >> w;  sum+=w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(0, -1, 0);
    cout << 2 * sum - mx << endl;
}