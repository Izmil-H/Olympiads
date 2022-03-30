#include <bits/stdc++.h>
using namespace std;
int N, M, T, Q; vector<int> adj[1001];
int bfs(int st, int ed){
    queue<int> q; bool vis[1001]; int dis[1001];
    memset(vis, 0, sizeof(vis));  // fill(vis, vis+1001, 0);
    q.push(st); vis[st]=1; dis[st]=0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                q.push(nxt); vis[nxt] = 1; dis[nxt] = dis[cur] + 1;
            }
            if(vis[ed]) return dis[ed];
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d", &N, &M, &T);
    for(int i=1, u, v; i<=M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    scanf("%d", &Q);
    for(int i=1, a, b; i<=Q; i++){
        scanf("%d %d", &a, &b);
        int ans = bfs(a, b) * T;
        if(ans < 0) printf("Not enough hallways!\n");
        else printf("%d\n", ans);
    }
}