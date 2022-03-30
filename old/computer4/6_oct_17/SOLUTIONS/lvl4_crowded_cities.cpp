#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, SZ=5001;
struct block {
    int l, w, h, p, id;
}a[MM];
int N, last; ll bit[SZ][SZ], dp[MM], ans;
bool cmp(block& a, block& b) { return a.h < b.h || a.h==b.h&&a.l<b.l || a.h==b.h&&a.l==b.l&&a.w<b.w;}
void update(int r, int c, ll val){
    for(int i=r; i<SZ; i+=i&-i)
        for(int j=c; j<SZ; j+=j&-j)
            bit[i][j] = max(bit[i][j], val);
}
ll query(int r, int c){
    ll ret = 0;
    for(int i=r; i>0; i-=i&-i)
        for(int j=c; j>0; j-=j&-j)
            ret = max(ret, bit[i][j]);
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> a[i].l >> a[i].w >> a[i].h >> a[i].p; a[i].id=i;
        if(a[i].l < a[i].w) swap(a[i].l, a[i].w);
    }
    sort(a+1, a+N+1, cmp);
    for(int i=1; i<=N; i++) {
        dp[i] = query(a[i].l, a[i].w) + a[i].p;
        update(a[i].l, a[i].w, dp[i]);
        if(dp[i] > ans) { ans = dp[i]; last = i; }
    }
    vector<int> vec;  vec.push_back(a[last].id);
    for(int i=last, j=last-1; j>0; j--){
        if(dp[j] == dp[i] - a[i].p && a[i].l >= a[j].l && a[i].w >= a[j].w) {
            vec.push_back(a[j].id); i=j;
        }
    }
    cout << ans << endl << vec.size() << endl;
    for(int x : vec) cout << x << " ";
}