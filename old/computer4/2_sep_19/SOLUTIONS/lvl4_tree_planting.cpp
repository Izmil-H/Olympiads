#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2010, mod = 1e9+7;
int n; ll bit[MM][MM], ans;
void update(ll bit[], int pos, int val){
    for(int i=pos; i<MM; i+=i&-i)
        bit[i] += val;
}
ll query(ll bit[], int pos){
    ll sum = 0;
    for(int i=pos; i>0; i-=i&-i)
        sum += bit[i];
    return sum;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, op, r, c, val; i<=n; i++){
        cin >> op >> r >> c >> val;
        if(op == 1) update(bit[r+c], r, val);
        else ans = (ans + query(bit[r+c], r) - query(bit[r+c], r-val-1) + mod) % mod;
    }
    cout << ans << endl;
}