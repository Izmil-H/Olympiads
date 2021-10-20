#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3002;
int N, K, a[MM][MM];  ll ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=i; j++)
            cin >> a[i][j];
    int cur = 0, nxt = 0;
    for(cur=1, nxt=2; nxt <= K; cur=nxt, nxt=(int)(1.5*cur)){
        int d = nxt - cur;
        for(int i=1; i<=N-nxt+1; i++){
            for(int j=1; j<=i; j++){
                a[i][j] = max(a[i][j], max(a[i+d][j], a[i+d][j+d]));
            }
        }
    }
    int d = K - cur;
    for(int i=1; i<=N-K+1; i++)
        for(int j=1; j<=i; j++)
            ans += max(a[i][j], max(a[i+d][j], a[i+d][j+d]));
    cout << ans << endl;
}