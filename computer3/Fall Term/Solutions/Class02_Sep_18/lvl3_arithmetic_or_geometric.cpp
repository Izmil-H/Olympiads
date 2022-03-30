#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int T; ll a, b, c, k;
ll quick_pow(ll x, ll exp){
    if(exp == 0) return 1;
    ll tmp = quick_pow(x, exp/2);
    tmp = tmp*tmp % mod;
    return (exp&1) ? tmp*x%mod: tmp;
}
int main(){
    for(cin>>T; T--; ){
        cin >> a >> b >> c >> k;
        if(b-a == c-b) cout << (a + (k-1)*(b-a)%mod)%mod << "\n";
        else cout << quick_pow(b/a, k-1)*a%mod << "\n";
    }
}