#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+4;
int n, dis[MM], len, far; vector<int> adj[MM];
void bfs(int s){
    fill(dis, dis+n+1, -1);
    queue<int> q;
    q.push(s); dis[s]=0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dis[u] > len) { len = dis[u]; far = u; }
        for(int v : adj[u]){
            if(dis[v]==-1) {
                q.push(v); dis[v]=dis[u]+1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=1, u, v; i<n; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    bfs(1); len=0; bfs(far);
    cout << len << endl;
}