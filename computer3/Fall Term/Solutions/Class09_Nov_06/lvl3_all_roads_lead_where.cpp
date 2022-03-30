#include <bits/stdc++.h>
using namespace std;
int n, m, adj[27][27], idx, pre[27]; unordered_map<string, int> mp; bool vis[27]; string city[27];
void bfs(int st){
    memset(vis, 0, sizeof(vis)); queue<int> q;
    q.push(st); vis[st]=true; pre[st] = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<=26; v++){
            if(!vis[v] and adj[u][v]){
                q.push(v); vis[v]=true; pre[v]=u;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string u, v;
        cin >> u >> v;
        if(!mp.count(u)) { mp[u] = ++idx; city[idx]=u;}
        if(!mp.count(v)) { mp[v] = ++idx; city[idx]=v;}
        adj[mp[u]][mp[v]] = adj[mp[v]][mp[u]] = 1;
    }
    for(int i=1; i<=m; i++){
        string st, ed, ans = "";
        cin >> st >> ed;
        bfs(mp[st]);
        for(int u=mp[ed]; u!=-1; u=pre[u]){
            ans += city[u][0];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}