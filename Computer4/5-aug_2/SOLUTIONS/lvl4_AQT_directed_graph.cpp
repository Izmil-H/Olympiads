#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2;
int N, M, ans[MM]; vector<int> adj[MM];
void dfs(int u, int val){
    ans[u] = val;
    for(int v: adj[u]){
        if(!ans[v]) dfs(v, val);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, u, v; i<=M; i++){
        cin >> u >> v;  adj[v].push_back(u);
    }
    for(int i=N; i>=1; i--){
        if(!ans[i]) dfs(i, i);
    }
    for(int i=N; i>=1; i--){
        if(ans[i] > i) {
            cout << i << " " << ans[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}