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
typedef pair<ll, int> pli;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1002;
int n, m, q, cnt; ll dis[MM]; unordered_map<string, int> mp; string a, b; vii adj[MM];
void dijkstra(int st, int ed){
    priority_queue<pli, vector<pli>, greater<pli>> q;
    cl(dis, 0x3f); dis[st] = 0; q.push({0, st});
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]){
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1, t; i<=m; i++) {
        cin >> a >> b >> t;
        if(!mp.count(a)) mp[a] = ++cnt;
        if(!mp.count(b)) mp[b] = ++cnt;
        adj[mp[a]].pb({mp[b], t});
    }
    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> a >> b;
        dijkstra(mp[a], mp[b]);
        if(dis[mp[b]] >= infl) cout << "Roger\n";
        else cout << dis[mp[b]] << "\n";
    }
}