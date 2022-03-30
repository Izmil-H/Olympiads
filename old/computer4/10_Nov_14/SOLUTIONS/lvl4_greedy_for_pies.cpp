#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
int N, a[MM], M, b[103], dp[MM][2][103][103];
int fun(int i, int can, int L, int R){
    if (dp[i][can][L][R] != 0) return dp[i][can][L][R];
    int best = 0;
    if(i <= N){
        best = max(best, fun(i+1, true, L, R));
        if(can) {
            best = max(best, a[i] + fun(i+1, false, L, R));
        }
    }
    if(L <= R){
        best = max(best, fun(i, true, L+1, R));
        if(can){
            best = max(best, b[R] + fun(i, false, L, R-1));
        }
    }
    return dp[i][can][L][R] = best;
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> a[i];
    cin >> M;
    for(int i=1; i<=M; i++) cin >> b[i];
    sort(b+1, b+M+1);
    cout << fun(1, 1, 1, M) << endl;
}