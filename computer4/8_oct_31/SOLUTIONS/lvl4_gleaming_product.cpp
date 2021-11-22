#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7;
int N, mx, rit, ans; vii vec;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i=0, x, y; i<N; i++){
        cin >> x >> y;
        vec.pb({x, y}); vec.pb({y, -x});
    }
    sort(vec.begin(), vec.end());
    for(pi& e: vec){
        if(e.s > 0){
            mx = max(mx, e.s);
        }else {
            int lft = -e.s;
            if(lft >= rit) { ans++; rit = mx;}
        }
    }
    cout << ans << endl;
}