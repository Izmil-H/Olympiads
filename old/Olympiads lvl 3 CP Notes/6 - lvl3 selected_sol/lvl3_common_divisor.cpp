#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, k; vector<ll> f1, f2;
int main(){
    cin >> a >> b >> k;
    ll g = __gcd(a, b), up=sqrt(g);
    for(ll i=1; i<up; i++){
        if(g %i == 0) { f1.push_back(i); f2.push_back(g/i); }
    }
    if(up*up==g) f1.push_back(up);
    for(int i=f2.size()-1; i>=0; i--) f1.push_back(f2[i]);
    cout << f1[f1.size()-k] << endl;
}