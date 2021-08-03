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
const int mod = 1e9 + 7, MM = 4e5+5;
int N, K, t[MM], x[MM], y[MM];
bool check(ll m){
    ll xmi = x[1]-m, xmx = x[1], ymi = y[1]-m, ymx = y[1];
    for(int i=2; i<=N; i++) {
        ll d = 1LL*(t[i] - t[i-1])*K;
        xmi = max(xmi - d, x[i] - m); ymi = max(ymi - d, y[i] - m);
        xmx = min(xmx + d, (ll)x[i]); ymx = min(ymx + d, (ll)y[i]);
        if(xmi > xmx || ymi > ymx) return false;
    }
    return true;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    ll lo = 0, hi = 1e10, ans = 0;
    while(lo <= hi) {
        ll mid = lo + hi >> 1;
        if(check(mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    cout << ans << endl;
}