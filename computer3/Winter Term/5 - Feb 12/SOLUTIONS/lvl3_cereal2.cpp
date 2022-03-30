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
const int mod = 1e9 + 7, MM = 1e5+5;
struct E { int u, v, w;};
int N, M, p[MM]; vi sad, ans; vii adj[MM]; bool vis[MM], used[MM]; vector<E> cycle;
int fd(int d){ return d==p[d]? p[d]: p[d]=fd(p[d]);}
void dfs(int u){
    vis[u] = true;
    for(auto [v, w] : adj[u]){
        if(!vis[v]){ ans.pb(w); dfs(v); }
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=M; i++) p[i] = i;
    for(int i=1, u, v; i<=N; i++){
        cin >> u >> v; used[u] = used[v] = 1;
        int fu = fd(u), fv =fd(v);
        if(fu != fv) {
            adj[u].pb({v, i}); adj[v].pb({u, i}); p[fu] = fv;
        }else {
            cycle.pb(E{u, v, i});
        }
    }
    for(auto [u, v, w] : cycle){
        if(vis[u]) { sad.pb(w); continue; }
        ans.pb(w); dfs(u);
    }
    cout << sad.size() << endl;
    for(int i=1; i<=M; i++){
        if(p[i] != i || !used[i] || vis[i]) continue;
        dfs(i);
    }
    for(int x : ans) cout << x << "\n";
    for(int x : sad) cout << x << "\n";
}