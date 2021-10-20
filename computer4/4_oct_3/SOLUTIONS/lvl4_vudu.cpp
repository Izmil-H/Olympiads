#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, P, bit[MM]; ll psa[MM], ans, a[MM];
void update(int pos, int val){
    for(int i=pos; i<=N+1; i+=i&-i) bit[i] += val;
}
int query(int pos){
    int ret = 0;
    for(int i=pos; i>0; i-=i&-i) ret += bit[i];
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> psa[i];
    cin >> P;
    for(int i=1; i<=N; i++){
        psa[i] = psa[i] - P + psa[i-1]; a[i] = psa[i];
    }
    sort(a, a+N+1);
    for(int i=0; i<=N; i++){
        int rk = lower_bound(a, a+N+1, psa[i]) - a + 1;
        ans += query(rk); update(rk, 1);
    }
    cout << ans << endl;
}