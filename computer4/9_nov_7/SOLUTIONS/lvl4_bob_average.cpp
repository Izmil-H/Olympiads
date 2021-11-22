#include <bits/stdc++.h>
using namespace std;
int N, X, sum; long long ans, dp[51][2510];
int main(){
    //freopen("test.txt", "r", stdin);
    cin >> N >> X;
    dp[0][0] = 1;
    for(int i=1, v; i<=N; i++) {
        cin >> v;  sum+=v;
        for(int j=i; j>=1; j--) {
            for(int k=v; k<=sum; k++){
                dp[j][k] += dp[j-1][k-v];
            }
        }

    }
    for(int i=1; i<=N; i++) ans += dp[i][i*X];
    cout << ans << endl;
}