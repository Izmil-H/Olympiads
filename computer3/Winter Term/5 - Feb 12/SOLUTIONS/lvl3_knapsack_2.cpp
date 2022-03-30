#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, W, dp[MM];
int main(){
    cin >> N >> W; memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i=1, w, v; i<=N; i++){
        cin >> w >> v;
        for(int j=MM-1; j>=v; j--)
            dp[j] = min(dp[j], dp[j-v] + w);
    }
    for(int i=MM-1; i>=0; i--)
        if(dp[i] <= W) { cout << i << endl;  return 0;}
}