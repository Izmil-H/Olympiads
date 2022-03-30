#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int N, W; ll dp[MM];
int main(){
    cin >> N >> W;
    for(int i=1, v, c; i<=N; i++){
        cin >> c >> v;
        for(int j=W; j>=c; j--)
            dp[j] = max(dp[j], dp[j-c] + v);
    }
    cout << dp[W] << "\n";
}