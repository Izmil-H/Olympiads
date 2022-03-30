#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 2e5+3;
int N, Q, a[MM], bit[2][MM];
void upd(int k, int idx, int val){
    for(int i=idx; i<=N; i+=i&-i) bit[k][i]^=val;
}
int qry(int k, int idx){
    int ret = 0;
    for(int i=idx; i; i-=i&-i) ret ^= bit[k][i];
    return ret;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        cin >> a[i]; upd(i&1, i, a[i]);
    }
    for(int i=1, op, x, y; i<=Q; i++){
        cin >> op >> x >> y;
        if(op == 1) {
            upd(x&1, x, a[x]^y); a[x] = y;
        }else{
            if((x&1) ^ (y&1)) cout << 0 << "\n";
            else cout << (qry(y&1, y) ^ qry(y&1, x-1)) << "\n";
        }
    }
}