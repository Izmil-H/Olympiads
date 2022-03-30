#include <bits/stdc++.h>
using namespace std;
int N, M, W, ant[105], dis[105]; vector<int> adj[105]; bool vis[105]; queue<int> Q;
int main(){
    cin >> N >> M;
    for(int i=0, x, y; i<M; i++){
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    cin >> W;
    for(int i=0, x; i<W; i++){
        cin >> x;
        Q.push(x); ant[x]=0; vis[x]=1;
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                Q.push(nxt); ant[nxt]=ant[cur]+4; vis[nxt]=1;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    Q.push(1); dis[1]=0; vis[1]=1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt] && dis[cur]+1 < ant[nxt]){
                dis[nxt]=dis[cur]+1; vis[nxt]=1; Q.push(nxt);
            }
        }
    }
    if(vis[N]) cout << dis[N] << endl;
    else cout << "sacrifice bobhob314" << endl;
}