#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pi;
int N, K, lo[MM], hi[MM], s[MM]; vector<pi> adj[MM];
void dfs(int u, int pa, int L, int R){
    lo[u] = L; hi[u] = R;
    vector<pi> &vec = adj[u];
    for(int i=0; i<vec.size(); i++){
        if(vec[i].second == pa) vec.erase(vec.begin()+i);
    }
    if(vec.empty()) return;
    sort(vec.begin(), vec.end());
    lo[vec[0].second]=L;  hi[vec.back().second] = R;
    for(int i=0; i < vec.size(); i++){
        int w = vec[i].first, v = vec[i].second;
        if(i > 0) lo[v] = max((vec[i-1].first + vec[i].first)/2+1, L);
        if(i+1 < vec.size()) hi[v]=min((vec[i].first + vec[i+1].first)/2, R);
        dfs(v, u, lo[v], hi[v]);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); adj[v].push_back({w,u});
    }
    for(int i=1; i<=K; i++) cin >> s[i];
    dfs(1, 0, 1, 1e9);  sort(s, s+K+1);
    for(int i=1; i<=N; i++){
        if(lo[i] > hi[i]) cout << 0;
        else cout << upper_bound(s, s+K+1, hi[i]) - lower_bound(s, s+K+1, lo[i]);
        cout << " \n"[i==N];
    }
}