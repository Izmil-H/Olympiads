#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int N, M, p, q; vector<int> adj[MM]; bool vis[MM];
bool bfs(int st, int ed){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(st); vis[st]=1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){ vis[nxt]=1; q.push(nxt); }
        }
        if(vis[ed]) return true;
    }
    return false;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, x, y; i<=M; i++){
        cin >> x >> y; adj[x].push_back(y);
    }
    cin >> p >> q;
    if(bfs(p, q)) cout << "yes\n";
    else if(bfs(q, p)) cout << "no\n";
    else cout << "unknown\n";
}