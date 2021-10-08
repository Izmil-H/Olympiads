#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1.5e5+5;
int N, psa[MM], bit[2*MM]; ll ans = 0;
void update(int pos, int val){
    pos += N + 1;
    for(int i=pos; i<=2*N+1; i+=i&-i)
        bit[i] += val;
}
int query(int pos){
    pos += N + 1;  ll sum = 0;
    for(int i=pos; i>0; i-=i&-i)
        sum += bit[i];
    return sum;
}
int main(){
    cin >> N;
    for(int i=1, x; i<=N; i++){
        cin >> x;
        psa[i] = psa[i-1] + (x==1? 1:-1);
    }
    update(0, 1);
    for(int i=1; i<=N; i++){
        ans += query(psa[i] - 1);
        update(psa[i], 1);
    }
    cout << ans << endl;
}