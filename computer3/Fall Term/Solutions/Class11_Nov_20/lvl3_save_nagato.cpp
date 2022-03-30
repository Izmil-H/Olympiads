#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int n, d1[MM], d2[MM], dp[MM], ans[MM]; vector<int> adj[MM];
void dfs1(int u, int pa){
    for(int v: adj[u]){
        if(v == pa) continue;
        dfs1(v, u);
        if(d1[v] + 1 > d1[u]) {
            d2[u] = d1[u]; d1[u] = d1[v]+1;
        }else if(d1[v] + 1 > d2[u]) {
            d2[u] = d1[v] + 1;
        }
    }
}
void dfs2(int u, int pa){
    ans[u] = max(dp[u], d1[u]);
    for(int v: adj[u]) {
        if(v == pa) continue;
        if(d1[v] + 1 == d1[u]) {
            dp[v] = max(dp[u], d2[u]) + 1;
        }else {
            dp[v] = max(dp[u], d1[u]) + 1;
        }
        dfs2(v, u);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, u, v; i<n; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(1, 0);  dfs2(1, 0);
    for(int i=1; i<=n; i++)
        cout << ans[i] + 1 << "\n";
}