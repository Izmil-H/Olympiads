#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
struct E { int u, v, w; };
int n, m, d, p[MM], ans; vector<E> edge;
bool cmp(E a, E b){ return a.w > b.w; }
int find_set(int d) {
    if(d != p[d]) p[d] = find_set(p[d]);
    return p[d];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> d;
    for(int i=1, u, v, w; i<=m; i++) {
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    for(int i=1; i<=n; i++) p[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    for(int i=0, j=0, dest=0; j<d; j++){
        cin >> dest;
        while(find_set(dest) != find_set(1)){
            int fu = find_set(edge[i].u), fv = find_set(edge[i].v);
            if(fu != fv) p[fu] = fv;
            ans = edge[i].w;  i++;
        }
    }
    cout << ans << endl;
}