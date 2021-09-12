#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
//#pragma GCC optimize("Ofast")
#define INF 0x3f3f3f3f
typedef pair<int, int> pi;
const int MM = 200002;
int N, M, ans[MM]; vector<pi> adj[MM];
bool inq[MM];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    queue<int> q;
    q.push(1); ans[1] = INF; inq[1]=true;
    while(!q.empty()){
        int cur = q.front(); q.pop();  inq[cur]=false;
        for(pi nxt: adj[cur]){
            int v = nxt.first, w = nxt.second;
            if(ans[v] < min(w, ans[cur])) {
                ans[v] = min(w, ans[cur]);
                if(!inq[v]){ q.push(v);  inq[v] = true;}
            }
        }
    }
    cout << 0 << "\n";
    for(int i = 2; i <= N; i++){
        cout << ans[i] << "\n";
    }
}