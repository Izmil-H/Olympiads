#include <bits/stdc++.h>
using namespace std;
int M, U, R, dp[152][302][102], V[152], T[152], F[152];
int main(){
    scanf("%d %d %d", &M, &U, &R);
    for(int i=1; i<=R; i++)
        scanf("%d %d %d", &V[i], &T[i], &F[i]);
    for(int i=1; i<=R; i++)
        for(int j=1; j<=M; j++){
            for(int k=1; k<=U; k++){
                if(T[i]>j || F[i]>k) dp[i][j][k] = dp[i-1][j][k];
                else dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-T[i]][k-F[i]]+V[i]);
            }
        }
    printf("%d", dp[R][M][U]);
}