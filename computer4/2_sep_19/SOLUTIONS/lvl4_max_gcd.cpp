#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int n, a[MM], pre[MM], suf[MM], ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pre[i] = __gcd(pre[i-1], a[i]);
    }
    for(int i=n; i>=1; i--) {
        suf[i] = __gcd(suf[i+1], a[i]);
    }
    for(int i=1; i<=n; i++) {
        ans = max(ans, __gcd(pre[i-1], suf[i+1]));
    }
    cout << ans << endl;
}