#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e5+5, mod = 1e9+7;
int n, a[MM], given, p[MM], val[MM], bit[MM]; ll ans; bool vis[MM];
int query(int pos){
    int ret = 0;
    for(int i=pos; i>0; i-=i&-i) ret += bit[i];
    return ret;
}
void update(int pos, int val){
    for(int i=pos; i<=n; i+=i&-i) bit[i] += val;
}
ll qpow(ll x, ll exp){
    if(exp == 0) return 1;
    ll t = qpow(x, exp/2);
    t = t*t % mod;
    return (exp&1)? t*x%mod : t;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i]) {
            ans += given - query(a[i]);
            update(a[i], 1); given++;  vis[a[i]]=1;
        }else { //missing
            p[i] = 1;
        }
    }
    ans %= mod;
    if(given != n){
        ll k = n-given, inv = qpow(k, mod-2);
        ans = (ans + k*(k-1)%mod * qpow(4, mod-2)%mod)%mod;
        for(int i=1; i<=n; i++) {
            p[i] += p[i-1];  val[i] = val[i-1] + !vis[i];
        }
        for(int i=1; i<=n; i++) {
            if(!a[i]) continue;
            ans += 1LL * p[i] * (val[n] - val[a[i]]) % mod * inv % mod;
            ans += 1LL * (p[n] - p[i]) * val[a[i]] % mod * inv % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}