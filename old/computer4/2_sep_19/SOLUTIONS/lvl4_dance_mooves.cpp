#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, K, a[MM], ans[MM]; vector<int> pos[MM]; bool vis[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        a[i] = i;  pos[a[i]].push_back(i);
    }
    for(int i=1, x, y; i<=K; i++) {
        cin >> x >> y;
        pos[a[x]].push_back(y); pos[a[y]].push_back(x);
        swap(a[x], a[y]);
    }
    for(int i=1; i<=N; i++){
        if(vis[i]) continue;
        vector<int> cycle; int u = i;
        for( ; u!=i || cycle.empty(); u = a[u]){
            vis[u] = true; cycle.push_back(u);
        }
        unordered_set<int> st;
        for(int x : cycle)
            st.insert(pos[x].begin(), pos[x].end());
        for(int x : cycle)
            ans[x] = st.size();
    }
    for(int i=1; i<=N; i++) cout << ans[i] << "\n";
}