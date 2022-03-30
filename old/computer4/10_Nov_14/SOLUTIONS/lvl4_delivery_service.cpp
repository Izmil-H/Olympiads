#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7, MM = 1e5+3;
int X, D, N, P, W, f[MM], dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> X;
    if(X==1){
        cin >> D >> N >> P;
        for(int i=1, pos, fuel; i<=P; i++) {
            cin >> pos >> fuel;
            f[pos] = fuel;
        }
        dp[0]=0;  dp[1]++;  dp[N+1]--;
        for(int i=1; i<=D; i++) {
            dp[i] = (dp[i] + dp[i-1])%mod;
            if(f[i]) {
                dp[i+1] = (dp[i+1] + dp[i]) % mod;
                int t = min(i+f[i]+1, D+1);
                dp[t] = (dp[t] - dp[i] + mod)%mod;
            }
        }
        cout << dp[D] << endl;
    }else{
        cin >> W; int num = 30, dst = num+2;
        cout << (num+2) << " " << num << " " << num << endl;
        for(int i=1; i<=num; i++) {
            if(W & 1<<(i-1)) cout << i << " " << dst - i << endl;
            else cout << i << " " << dst - 1 - i << endl;
        }
    }
}