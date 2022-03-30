#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, mod = 1e9+7;
ll fact[MM], inv[MM], ans; int N, K, a[MM];
ll qpow(ll x, int exp){
    if(exp == 0) return 1;
    ll t = qpow(x, exp/2);
    t = t*t % mod;
    return exp % 2 != 0? t*x%mod: t;
}
void preproc(){
    fact[0] = inv[0] = 1;
    for(int i=1; i<=N; i++) fact[i] = i * fact[i-1] % mod;
    for(int i=1; i<=N; i++) inv[i] = qpow(fact[i], mod-2);
}
ll choose(int n, int k){
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}
int main(){
    cin >> N >> K; preproc();
    for(int i=1; i<=N; i++) cin >> a[i];
    sort(a+1, a+N+1);
    for(int i=K; i<=N; i++){
        ans = (ans + a[i] * choose(i-1, K-1) % mod) % mod;
    }
    cout << ans << endl;
}