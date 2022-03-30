#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int N, M, st, ed, dis[MM]; vector<int> adj[MM]; bool vis[MM];
int main(){
    cin >> N >> M >> st >> ed;
    for(int i=1, u, v; i<=M; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    queue<int> q;
    q.push(st); vis[st]=true; dis[st]=0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                q.push(nxt); vis[nxt]=true;
                dis[nxt] = dis[cur] + 1;
            }
        }
    }
    if(vis[ed]) cout << "GO SHAHIR!" << endl;
    else cout << "NO SHAHIR!" << endl;
}