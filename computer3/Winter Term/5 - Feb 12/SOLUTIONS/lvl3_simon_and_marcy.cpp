#include <bits/stdc++.h>
using namespace std;
int C, M, dp[1001][1001];
int main(){
    cin >> C >> M;
    for(int i=1, v=0, w=0; i<=C; i++){
        cin >> v >> w;
        for(int j=1; j<=M; j++){
            if(w > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]);
        }
    }
    cout << dp[C][M] << endl;
}