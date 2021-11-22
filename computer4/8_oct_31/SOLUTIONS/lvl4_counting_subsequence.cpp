#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int dp[100002], last[26], n; string s;
int main(){
    cin >> s;  n = s.size();
    for(int i=1; i<=n; i++){
        int id = s[i-1] - 'a';
        if(last[id] == 0){
            dp[i] = (2*dp[i-1] + 1)%mod;
        }else{
            dp[i] = (2*dp[i-1] - dp[last[id]-1] + mod) % mod;
        }
        last[id] = i;
    }
    cout << dp[n] << endl;
}