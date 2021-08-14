#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+3, base = 131, base2=137, mod = 1e9+7;
string s, t; ll hsh[MM], hsh2[MM], pw[MM], pw2[MM]; unordered_set<ll> st;
ll getSubHash(int L, int R){
    ll v1 = (hsh[R] - hsh[L-1] * pw[R-L+1] % mod + mod)%mod;
    ll v2 = (hsh2[R] - hsh2[L-1] * pw2[R-L+1] % mod + mod)%mod;
    return (v1 << 31) | v2;
}
int main(){
    cin >> s >> t;  vector<int> fs(26), ft(26);
    int n = s.size(), m = t.size();
    for(int i=0; i<n; i++) fs[s[i]-'a']++;
    hsh[0] = 0; pw[0] = 1; hsh2[0] = 0; pw2[0] = 1;
    for(int i=1; i<=m; i++) {
        hsh[i] = (hsh[i-1] * base + t[i-1])%mod;
        pw[i] = pw[i-1] * base % mod;
        hsh2[i] = (hsh2[i-1] * base2 + t[i-1])%mod;
        pw2[i] = pw2[i-1] * base2 % mod;
    }
    for(int i=1; i<=m; i++) {
        ft[t[i-1]-'a']++;
        if(i > n) ft[t[i-n-1]-'a']--;
        if(i>=n && fs == ft) {
            //cout << t.substr(i-n, n) << " " << getSubHash(i-n+1, i) << endl;
            st.insert(getSubHash(i-n+1, i));
        }
    }
    cout << st.size() << endl;
}