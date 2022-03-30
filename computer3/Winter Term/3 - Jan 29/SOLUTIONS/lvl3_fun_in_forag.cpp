#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, pair<int, long long>> piii;
const int sz=2e5+2;
int n, m, a, b, vis[sz];
ll c, dis[sz];
vector<piii> adj[sz];
ll fun(int cc){
    priority_queue<pli, vector<pli>, greater<pli>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[a]=0;
    q.push({0, a});
    while(!q.empty()){
        ll d = q.top().f; int u = q.top().s;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(piii nxt: adj[u]){
            int id = nxt.f, v = nxt.s.f; ll w = nxt.s.s;
            if(dis[v]> dis[u]+w && id<=cc){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    return dis[b];
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int l = 1, r = m, ans=-1;
    for(int i=1;i<=m;i++){
        int x, y; ll z;
        cin >> x >> y >> z;
        adj[x].push_back({i, {y, z}});
        adj[y].push_back({i, {x, z}});
    }
    cin >> a >> b >> c;
    while(l<=r){
        int mid=(l+r)/2;
        if(fun(mid) < c){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}