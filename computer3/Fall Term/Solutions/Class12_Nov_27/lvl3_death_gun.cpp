#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MM = 2000;
priority_queue<int, vector<int>, greater<int> > q;
int m, in[MM]; vector<int> adj[MM];
unordered_map<string, int> mp; vector<string> vec;
int main(){
    cin >> m;
    for(int i=1; i<=m; i++) {
        string a, b;
        cin >> a >> b;
        if(!mp.count(a)) {mp[a] = vec.size(); vec.pb(a);}
        if(!mp.count(b)) {mp[b] = vec.size(); vec.pb(b);}
        adj[mp[b]].pb(mp[a]);  in[mp[a]]++;
    }
    for(int i=0; i<vec.size(); i++){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.top(); q.pop();
        cout << vec[u] << "\n";
        for(int v: adj[u])
            if(--in[v] == 0) q.push(v);
    }
}