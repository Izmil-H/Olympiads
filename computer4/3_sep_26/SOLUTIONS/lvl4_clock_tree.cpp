#include <bits/stdc++.h>
using namespace std;
const int MM = 2502;
int N, a[MM], b[MM], ans; vector<int> adj[MM];
void dfs(int u, int pre) {
    for(int v: adj[u]){
        if(v == pre) continue;
        dfs(v, u);
        b[u] = (b[u] + 12 - b[v])%12;
    }
}
int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    for(int i=1, u, v; i<N; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        memcpy(b, a, sizeof(a));
        dfs(i, 0);
        if(b[i] == 0 || b[i] == 1) ans++;
    }
    printf("%d\n", ans);
}