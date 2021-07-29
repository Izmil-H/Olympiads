#include <bits/stdc++.h>
using namespace std;
int T, n; string s;
int main(){
    for(cin >> T; T--; ){
        cin >> n >> s;  vector<int> r(n+1), w(n+1);
        for(int i=1; i<=n; i++) {
            r[i] = r[i-1] + (s[i-1] == 'R');
            w[i] = w[i-1] + (s[i-1] == 'W');
        }
        int mi = w[1] - r[1], ans = n+1;
        for(int i=2; i<n; i++){
            ans = min(ans, w[n]-w[i]+r[i]+mi);
            mi = min(mi, w[i] - r[i]);
        }
        cout << ans << "\n";
    }
}