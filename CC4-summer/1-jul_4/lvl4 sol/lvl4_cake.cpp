#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K, Q; ll dif[5002][5002], psa[5002][5002];
int main(){
    scanf("%d %d %d", &N ,&M, &K);
    for(int i=1, x1, x2, y1, y2; i<=K; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x2++; y2++;
        dif[x1][y1]++; dif[x1][y2]--; dif[x2][y1]--; dif[x2][y2]++;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            psa[i][j] = dif[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    scanf("%d", &Q);
    for(int i=1,x1,x2,y1,y2; i<=Q; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--; y1--;
        printf("%lld\n", psa[x2][y2]-psa[x1][y2]-psa[x2][y1]+psa[x1][y1]);
    }
}