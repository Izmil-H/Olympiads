#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, a[MM], pre[MM], suf[MM];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a[i];
        pre[i] = __gcd(pre[i-1], a[i]);
    }
    for(int i=N; i>=1; i--){
        suf[i] = __gcd(suf[i+1], a[i]);
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        ans = max(ans, __gcd(pre[i-1], suf[i+1]));
    }
    cout << ans << endl;
}