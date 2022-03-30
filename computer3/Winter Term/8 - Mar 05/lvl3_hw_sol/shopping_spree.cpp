#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1003;
int N, M, W, cost[MM], val[MM]; ll dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> W;
    for(int i=1; i<=N; i++) {
        cin >> cost[i] >> val[i];
        for(int j=cost[i]; j<=W; j++)
            dp[j] = max(dp[j], dp[j-cost[i]] + val[i]);
    }
    for(int i=1, q, t, d, a; i<=M; i++) {
        cin >> q >> t >> d >> a;
        for(int k=1; k<=a; k*=2) {
            int w = d*k; ll v = 1LL*q*val[t]*k;
            for(int j=W; j>=w; j--)
                dp[j] = max(dp[j], dp[j-w] + v);
            a -= k;
        }
        if(a) {
            int w = d*a; ll v = 1LL*q*val[t]*a;
            for(int j=W; j>=w; j--)
                dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    cout << dp[W] << endl;
}