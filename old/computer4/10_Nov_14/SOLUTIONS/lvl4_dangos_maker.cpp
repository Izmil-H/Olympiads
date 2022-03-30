#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
int N, M, dp[2*MM][3], ans; char a[MM][MM];
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf(" %s", a[i]+1);
    for(int i=1; i<=N+M-1; i++){
        int s = 1;
        for(int r=min(i,N), c=max(1, i-N+1); r>0&&c<=M; r--,c++,s++){
            dp[s][0] = max(dp[s-1][0], max(dp[s-1][1], dp[s-1][2]));
            dp[s][1] = 0; dp[s][2] = 0;
            if(a[r-1][c]=='R' && a[r][c]=='G' && a[r+1][c]=='W')
                dp[s][1] = max(dp[s-1][0], dp[s-1][1]) + 1;
            if(a[r][c-1]=='R' && a[r][c]=='G' && a[r][c+1]=='W')
                dp[s][2] = max(dp[s-1][0], dp[s-1][2]) + 1;
        }
        ans += max(dp[s-1][0], max(dp[s-1][1], dp[s-1][2]));
    }
    printf("%d\n", ans);
}