#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM =102;
int n; bool vis[MM]; vi adj[MM];
int bfs(int s) {
    queue<int> q; cl(vis, 0);
    q.push(s); vis[s] = 1; int cnt = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for(int v: adj[u]){
            if(!vis[v]) { q.push(v); vis[v]=1;}
        }
    }
    return cnt;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1, u, v; i<n; i++){
        cin >> u >> v; adj[v].pb(u);
    }
    for(int i=1; i<=n; i++){
        if(bfs(i) == n) {
            cout << i << endl; return 0;
        }
    }
    cout << -1 << endl;
}