#include <bits/stdc++.h>
using namespace std;
const int MM = 26;
int adj[MM][MM], cnt; vector<string> vec; string s;
bool bfs(int st, int ed){
    queue<int> q; vector<bool> vis(26, false);
    q.push(st); vis[st]=1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt=0; nxt < 26; nxt++) {
            if(adj[cur][nxt] && !vis[nxt]){
                q.push(nxt); vis[nxt]=1;
            }
        }
        if(vis[ed]) return true;
    }
    return false;
}
int main(){
    while(true) {
        cin >> s;
        if(s == "**") break;
        vec.push_back(s);
        int u = s[0] - 'A', v = s[1] - 'A';
        adj[u][v] = adj[v][u] = 1;
    }
    for(string s : vec) {
        int u = s[0] - 'A', v = s[1] - 'A';
        adj[u][v] = adj[v][u] = 0;
        if(!bfs(0, 1)) { cout << s << endl; cnt++; }
        adj[u][v] = adj[v][u] = 1;
    }
    cout << "There are "<< cnt << " disconnecting roads." << endl;
}