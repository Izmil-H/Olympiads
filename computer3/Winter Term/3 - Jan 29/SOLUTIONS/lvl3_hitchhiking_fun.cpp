#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;  //< <int, int>, int >
const int MM = 1e5+5;
int N, M; vector<pi> adj[MM]; bool vis[MM]; pi dis[MM];
int main(){
    cin >> N >> M;
    for(int i=1, u, v, w; i<=M; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w}); adj[v].push_back({u,w});
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    memset(dis, 0x3f, sizeof(dis)); dis[1]={0, 0};
    q.push({dis[1], 1});
    while(!q.empty()){
        pii cur = q.top(); q.pop();
        pi d = cur.first; int u = cur.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(pi e : adj[u]){
            int v=e.first, w = e.second;
            pi tmp={dis[u].first + w, dis[u].second+1};
            if(dis[v] > tmp){
                dis[v] = tmp;
                q.push({dis[v], v});
            }
        }
    }
    if(!vis[N]) cout << -1 << endl;
    else cout << dis[N].first << " " << dis[N].second << endl;
}