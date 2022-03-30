#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll g = 0, ans = 0, x;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i <=n; i++) {
        cin >> x; g = __gcd(g, x);
    }
    for(ll i=2; i*i <= g; i++) {
        while(g % i == 0){
            ans = i; g /= i;
        }
    }
    if(g != 1) { ans = g; }
    if(ans > 0) cout << ans << "\n";
    else cout << "DNE\n";
}