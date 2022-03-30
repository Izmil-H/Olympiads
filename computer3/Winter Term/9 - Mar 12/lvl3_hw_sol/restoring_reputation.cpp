#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
int D, I, R, dp[MM][MM]; string A, B;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> D >> I >> R >> A >> B;
    int n = A.size(), m = B.size();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = I * j;
            else if(j == 0) dp[i][j] = D * i;
            else {
                if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1] + I, min(dp[i-1][j] + D, dp[i-1][j-1] + R));
            }
        }
    }
    cout << dp[n][m] << endl;
}