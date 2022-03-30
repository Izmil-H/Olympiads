#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b, g, k; vector<ll> f;
    cin >> a >> b >> k;
    g = __gcd(a, b);
    for(ll i=1; i*i<=g; i++) {
        if(g%i == 0) {
            f.push_back(i);
            if(g/i != i) f.push_back(g/i);
        }
    }
    sort(f.begin(), f.end(), greater<ll>());
    if(k > f.size()) cout << -1 << endl;
    else cout << f[k-1] << endl;
}