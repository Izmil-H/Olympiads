#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = (j+2)/3;
            else if(j == 0) dp[i][j] = (i+2)/3;
            else{
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j-1]+1;
                for(int k = 1; k <= 3; k++){
                    if(j>=k)dp[i][j] = min(dp[i][j], dp[i][j-k]+1);
                    if(i>=k)dp[i][j] = min(dp[i][j], dp[i-k][j]+1);
                }
            }
        }
    }
    cout << dp[n][m];
}