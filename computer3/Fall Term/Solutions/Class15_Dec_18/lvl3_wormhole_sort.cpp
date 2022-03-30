#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int MM = 1e5 + 5;
typedef pair<int, int> pi;
int N, M, p[MM], cnt, tot, start; bool need[MM], vis[MM]; vector<pi> adj[MM];
void dfs(int u, int lmt){
    vis[u] = true; tot += need[u];
    for(pi e: adj[u]){
        if(e.y < lmt || vis[e.x]) continue;
        dfs(e.x, lmt);
    }
}
bool check(int mid){
    memset(vis, 0, sizeof(vis)); tot = 0;
    dfs(start, mid);
    return tot == cnt;
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        scanf("%d", &p[i]);
        need[i] = (p[i] != i); cnt += need[i];
        if(need[i]) start = i;
    }
    if(cnt == 0){ printf("-1\n"); return 0;}
    int lo = 0, hi = 0, ans = 0;
    for(int i=1, u, v, w; i<=M; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w}); hi = max(hi, w);
    }
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid)){ ans = mid; lo = mid+1; }
        else hi = mid - 1;
    }
    printf("%d\n", ans);
}