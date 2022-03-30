#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3, mod=1e9+7;
int N, dp[MM];
int main(){
    scanf("%d", &N); dp[0] = 1;
    for(int i=0; i<20; i++){
        for(int j=(1<<i); j<=N; j++)
            dp[j] = (dp[j] + dp[j-(1<<i)])%mod;
    }
    printf("%d\n", dp[N]);
}