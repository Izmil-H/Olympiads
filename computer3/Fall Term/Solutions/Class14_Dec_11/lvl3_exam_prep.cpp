#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, Q, p[MM], sz[MM]; ll sum[MM];
int fd(int d){ return d==p[d]? p[d]: p[d]=fd(p[d]); }
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        p[i] = i; sz[i] = 1; cin >> sum[i];
    }
    for(int i=1, op, u, v; i<=Q; i++){
        cin >> op >> u;
        if(op == 1){
            cin >> v;
            int fu = fd(u), fv = fd(v);
            if(fu!=fv){ p[fu] = fv; sz[fv]+=sz[fu]; sum[fv] += sum[fu]; }
        }else if(op == 2) cout << sz[fd(u)] << "\n";
        else cout << sum[fd(u)] << "\n";
    }
}