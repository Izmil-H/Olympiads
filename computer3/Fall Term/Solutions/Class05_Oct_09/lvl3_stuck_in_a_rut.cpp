#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct inter{ int x, y, a, b; };
bool cmp(inter p, inter q) { return p.x < q.x || p.x==q.x && p.y < q.y;}
int n, x[102], y[102], ans[102]; bool stop[102]; char dir[102]; vector<inter> lst;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> dir[i] >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(dir[i] == dir[j]) continue;
            int ex = x[i], ey = y[i], nx = x[i], ny = y[i];
            if(dir[i] == 'E') { nx = x[j]; ny = y[j]; }
            else { ex = x[j]; ey = y[j]; }
            if(ex < nx && ny < ey) lst.push_back(inter{nx, ey, i, j});
        }
    }
    sort(lst.begin(), lst.end(), cmp);
    for(inter e : lst) {
        if(stop[e.a] || stop[e.b]) continue;
        int ta = e.x - x[e.a] + e.y - y[e.a], tb = e.x - x[e.b] + e.y - y[e.b];
        if(ta < tb) { stop[e.b] = true; ans[e.b] = tb; }
        else if(ta > tb) { stop[e.a] = true; ans[e.a] = ta; }
    }
    for(int i=1; i<=n; i++) {
        if(stop[i]) cout << ans[i] << endl;
        else cout << "Infinity" << endl;
    }
}