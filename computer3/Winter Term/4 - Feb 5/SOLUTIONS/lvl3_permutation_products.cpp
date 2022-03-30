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
const int mod = 1e9 + 7, MM = 1e5+5;
int N, ans[MM]; ll a[MM], mi = 1e18, mx = -1;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i=2; i<=N; i++) {
        cout << "? 1 " << i << "\n" << flush;
        cin >> a[i];
        mi = min(a[i], mi); mx = max(a[i], mx);
    }
    if(mi == 2) {
        if(mx > N) ans[1] = 2;
        else ans[1] = 1;
    }else {
        ans[1] = mi;
    }
    cout << "! " << ans[1];
    for(int i=2; i<=N; i++){
        ans[i] = a[i] / ans[1];
        cout << " " << ans[i];
    }
    cout << endl;
}