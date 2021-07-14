#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int M, N, K, dif[1002][30002], ans, cnt;
int main(){
    cin >> M >> N >> K;
    for(int i=1, x, y, r, b; i<=K; i++){
        cin >> x >> y >> r >> b;
        for(int j=max(1, x-r); j<=min(N, x+r); j++) {
            int d = sqrt(r*r - (x-j)*(x-j));
            dif[j][max(1, y-d)] += b;
            dif[j][min(M, y+d)+1] -= b;
        }
    }
    for(int j=1; j<=N; j++) {
        for(int i=1; i<=M; i++){
            dif[j][i] += dif[j][i-1];
            if(dif[j][i] > ans) {
                ans = dif[j][i]; cnt = 1;
            }else if(dif[j][i] == ans){
                cnt++;
            }
        }
    }
    cout << ans << endl << cnt << endl;
}