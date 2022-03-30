#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pl;
typedef pair<pl, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pli> vli;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 2e5+5;
int N, M, t[MM]; vii adj[MM]; ll dis[MM], ans;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1, u, v, w; i<=M; i++){
        cin >> u >> v >> w; adj[u].pb({v,w}); adj[v].pb({u,w});
    }
    priority_queue<pli, vli, greater<pli>> q; cl(dis, 0x3f);
    dis[1]=0; q.push({{0,t[1]}, 1}); int mi = t[1], lvl = 1;
    while(!q.empty()){
        ll d = q.top().f.f; int tt = q.top().f.s, u = q.top().s; q.pop();
        if(d > dis[u]) continue;
        if(dis[u] > lvl){
            ans += 1LL*mi*(dis[u]-lvl); lvl = dis[u];
        }
        if(u == N) { printf("%lld\n", ans); return 0;}
        mi = min(mi, t[u]);
        for(pi e: adj[u])
            if(e.s < dis[e.f]){ dis[e.f] = e.s; q.push({{dis[e.f], t[e.f]}, e.f}); }
    }
    printf("-1\n");
}