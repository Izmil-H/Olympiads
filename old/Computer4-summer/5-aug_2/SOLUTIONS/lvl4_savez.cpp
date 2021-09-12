#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+3, base = 131;
string s; unordered_map<ll, int> dp; int n, ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        ll pre = 0, suf = 0, pw = 1; int best = 0;
        for(int j=0; j<s.size(); j++){
            pre = pre*base + s[j];
            suf = s[(int)s.size()-j-1]*pw + suf;
            if(pre == suf && dp.count(pre)) best = max(best, dp[pre]);
            pw *= base;
        }
        dp[pre] = best+1;  ans = max(ans, best+1);
    }
    cout << ans << endl;
}