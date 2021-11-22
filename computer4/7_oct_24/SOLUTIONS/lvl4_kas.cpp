#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, tot, dp[502][MM], a[502];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> a[i]; tot += a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=tot; j++) {
            dp[i][j] = max(dp[i-1][j], max(dp[i-1][j+a[i]] + a[i], dp[i-1][abs(j-a[i])]+a[i]));
        }
    }
    cout << (tot - dp[N][0]/2) << endl;
}