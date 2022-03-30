#include <bits/stdc++.h>
using namespace std;
const int MM = 5002, MW = 5.5e4+5;
int N, M, v[MM], w[MM], dp[MW], ans = 1e9;
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) scanf("%d %d", &v[i], &w[i]);
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for(int i=1; i<=N; i++)
        for(int j=v[i]; j<MW; j++)
            dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
    for(int i=M; i<MW; i++) ans = min(ans, dp[i]);
    printf("%d\n", ans);
}