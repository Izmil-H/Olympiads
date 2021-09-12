#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int base = 131;
int n, m; vector<string> a, s; gp_hash_table<ll, int> mp; ll ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    if(n > m) {
        s.resize(m, string(n, ' '));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                s[i][j] = a[j][i];
        swap(s, a); swap(n, m);
    }
    for(int r1=0; r1<n; r1++){
        vector<ll> hsh(m, 0);
        for(int r2 = r1+1; r2 <n; r2++){
            for(int c=0; c<m; c++) hsh[c] = hsh[c]*base + a[r2][c];
            mp.clear();
            for(int c=0; c<m; c++){
                if(a[r1][c] == a[r2][c]){
                    ans += mp[hsh[c]]; mp[hsh[c]]++;
                }else{
                    mp.clear();
                }
            }
        }
    }
    cout << ans << endl;
}